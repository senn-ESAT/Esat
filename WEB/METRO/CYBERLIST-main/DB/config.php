<?php
session_start();
include("conection.php"); // Assicurati che questa connessione sia corretta

// Controllo che sia impostata la variabile di sessione "acc"
if (!isset($_SESSION["acc"])) {
  die("Azione non specificata.");
}

switch ($_SESSION["acc"]) {
  case 1: // LOGIN
    if (isset($_REQUEST['email']) && isset($_REQUEST['psw'])) {
      $email = $_REQUEST["email"];
      $psw = $_REQUEST["psw"];
            
      // Query sicura con prepared statement
      $stmt = $conn->prepare("SELECT user_id, psw FROM users WHERE email = ?");
      if ($stmt === false) {
        die("Prepare failed: " . $conn->error);
      }
      $stmt->bind_param("s", $email);
      $stmt->execute();
      $result = $stmt->get_result();

      if ($user = $result->fetch_assoc()) {
        // Verifica la password hashata
        if (password_verify($psw, $user['psw'])) {
          // Retrieve username and email along with user_id for session storage
          $user_id = $user["user_id"];
          $stmt = $conn->prepare("SELECT username, email FROM users WHERE user_id = ?");
          $stmt->bind_param("i", $user_id);
          $stmt->execute();
          $user_info = $stmt->get_result()->fetch_assoc();

          // Save user data to session
          $_SESSION["user"] = [
            "user_id" => $user_id,
            "username" => $user_info["username"],
            "email" => $user_info["email"]
          ];

          header("Location: ../index.php?acc=0&scelta=3");
          exit;
        } 
        else {
          die("Password errata.");
        }
      }
      else {
        die("Utente non trovato.");
      }
    }
    else {
      die("Dati login mancanti.");
    } 
  break;

  case 2: // REGISTER
    if (isset($_REQUEST['username']) && isset($_REQUEST['email']) && isset($_REQUEST['psw'])) {
      $username = $_REQUEST["username"];
      $email = $_REQUEST["email"];
      $psw = $_REQUEST["psw"];

      // Prima controlla che l'email o lo username non siano già usati
      $stmt = $conn->prepare("SELECT user_id FROM users WHERE email = ? OR username = ?");
      if ($stmt === false) {
        die("Prepare failed: " . $conn->error);
      }
      $stmt->bind_param("ss", $email, $username);
      $stmt->execute();
      $stmt->store_result();
      if ($stmt->num_rows > 0) {
        die("Email o username già in uso.");
      }

      // Hash della password
      $psw_hash = password_hash($psw, PASSWORD_DEFAULT);

      // Inserisci il nuovo utente
      $stmt = $conn->prepare("INSERT INTO users (username, email, psw) VALUES (?, ?, ?)");
      if ($stmt === false) {
        die("Prepare failed: " . $conn->error);
      }
      $stmt->bind_param("sss", $username, $email, $psw_hash);
      if (!$stmt->execute()) {
        die("Registrazione fallita: " . $stmt->error);
      }

      // Retrieve the newly inserted user's info
      $user_id = $conn->insert_id;
      $_SESSION["user"] = [
        "user_id" => $user_id,
        "username" => $username,
        "email" => $email
      ];

      header("Location: ../index.php?acc=0&scelta=3");
      exit;
    }
    else {
      die("Tutti i campi sono obbligatori.");
    }
  break;

  default:
  die("Azione non valida.");
}

header("Location: ../index.php");
exit;
?>