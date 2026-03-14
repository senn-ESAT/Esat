<!DOCTYPE html>
<html>
  <head>
    <title>CYBERPLANNER</title>
    <link rel="stylesheet" type="text/css" href="Home page\home.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400..900&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
    <header>
    <?php
      session_start();
      include("DB\conection.php");
      // sceglie la pagina da caricare
      if(isset($_REQUEST["scelta"])){
        $_SESSION["scelta"] = $_REQUEST["scelta"];
      }
      else{$_SESSION["scelta"] = 0;}
      
      // acc è la scelta che viene fatta nel dropdown del account
      if(isset($_REQUEST["acc"])){
        $_SESSION["acc"] = $_REQUEST["acc"];
      }
      else{$_SESSION["acc"] = 0;}

      //nullo se l'utente non ha loggato altrimenti non f aniente
      if (!isset($_SESSION["user"])) {
        $_SESSION["user"] = [
          "user_id" => null,
          "username" => null,
          "email" => null
        ];
      }   
          
      echo"
      <!--HEADER-->
      <div class='topbar'>
        <!--logo centrale-->
        <div class='logo-box'>
          <h1 class'logo'><a href='index.php?scelta=0' class='link'>CYBERPLANNER</a></h1>
        </div>
        <!--account-->
        <div class='dropdown'>
          <img src='Img/acc_light_blue.png' alt='account' class='dropdown-img'>
          <div class='dropdown-content'>
            <a href='index.php?acc=0&scelta=3' class='link'>ACCOUNT</a><br>
            <a href='index.php?acc=1&scelta=3' class='link'>LOGIN</a><br>
            <a href='index.php?acc=2&scelta=3' class='link'>REGISTER</a><br>
            <a href='index.php?scelta=4' class='link'>EXIT</a><br>
          </div>
        </div>
      </div>
    </header>";
    switch($_SESSION["scelta"]){
      case 0:
        echo include("Home page/home.php");
      break;
      case 1;
        echo include("Calendar/calendarR.php");
      break;
      case 2;
        echo include("Testing/testrut.php");
      break;
      case 3:
        echo include("Acc/account.php");
      break;
      case 4:
        $_SESSION["user"] = [
          "user_id" => null,
          "username" => null,
          "email" => null
        ];
      break;
    }
    ?>

    <!--footer-->
    <div class="links">
      <div class="col-sm-3"><a href='#' class='link' style="font-size: 15px;">PRIVACY POLICY</a></div>
      <div class="col-sm-3"><a href='#' class='link' style="font-size: 15px;">TERMS OF SERVICE</a></div>
      <div class="col-sm-3"><a href='#' class='link' style="font-size: 15px;">ABOUT US</a></div>
      <div class="col-sm-3"><a href='#' class='link' style="font-size: 15px;">FAQ</a></div>
    </div>
  </body>
</html>