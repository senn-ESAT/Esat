<?php
    session_start();
    include("config.php");
    $id = $_SESSION["id"];

    switch($_SESSION["scelta"]){
        case 1: //INSERISCI
            if(isset($_REQUEST['cognome']) && isset($_REQUEST['nome']) && isset($_REQUEST['eta']) && isset($_REQUEST['squadra'])){
                $cognome = $_REQUEST['cognome'];
                $nome = $_REQUEST['nome'];
                $eta = $_REQUEST['eta'];
                    $squadra = $_REQUEST['squadra'];
                if(isset($_REQUEST['titolare'])){
                    $titolare = 1;
                }
                else{
                    $titolare = 0;
                }
            
                $query = "INSERT INTO `anagrafica` ( `cognome`, `nome`, `eta`, `squadra`, `titolare`) VALUES ('$cognome', '$nome', $eta, '$squadra', $titolare)";
                @mysqli_query($conn, $query) or die("Query fallita");
            }
        break;

        case 2: //MODIFICA
            if(isset($_REQUEST['cognome']) && isset($_REQUEST['nome']) && isset($_REQUEST['eta']) && isset($_REQUEST['squadra'])){
                $cognome = $_REQUEST['cognome'];
                $nome = $_REQUEST['nome'];
                $eta = $_REQUEST['eta'];
                $squadra = $_REQUEST['squadra'];
                if(isset($_REQUEST['titolare'])){
                    $titolare = 1;
                }
                else{
                    $titolare = 0;
                }
            
                $query = "UPDATE anagrafica SET cognome = '$cognome', nome = '$nome', eta = '$eta', squadra = '$squadra', titolare = '$titolare' WHERE idanagrafica = $id";
                @mysqli_query($conn, $query) or die("Query fallita");
            }
        break;

        case 3: //ELIMINA
            $query = "DELETE FROM anagrafica WHERE `anagrafica`.`idanagrafica` = $id";
            @mysqli_query($conn, $query) or die("Query fallita");
        break;

        case 4: // ACCEDI
            if(isset($_REQUEST['mail']) && isset($_REQUEST['password'])){
                $mail = $_REQUEST['mail'];
                $password = $_REQUEST['password'];
        
                $query = "SELECT * FROM utenti WHERE mail = '$mail' AND password = '$password'";
                $result = mysqli_query($conn, $query) or die("Query fallita");
                
                // Verifica se la query ha trovato un utente
                if(mysqli_num_rows($result) > 0){
                    $_SESSION['risUtente'] = 1; // Imposta la variabile della sessione a 1 se l'utente è stato trovato
                } else {
                    $_SESSION['risUtente'] = 0; // Altrimenti, imposta la variabile della sessione a 0
                }
            }
        break;

        case 5: //REGISTRATI
            if(isset($_REQUEST['cognome']) && isset($_REQUEST['nome']) && isset($_REQUEST['mail']) && isset($_REQUEST['psw'])){
                $cognome = $_REQUEST['cognome'];
                $nome = $_REQUEST['nome'];
                $mail = $_REQUEST['mail'];
                $password = $_REQUEST['psw'];
                
                $query = "INSERT INTO `utenti` ( `cognome`, `nome`, `mail`, `password`) VALUES ('$cognome', '$nome', '$mail', '$password')";
                @mysqli_query($conn, $query) or die("Query fallita");
            }
        break;
    }
    header("Location:index.php");
?>