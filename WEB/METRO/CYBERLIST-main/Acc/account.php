<!DOCTYPE html>
<html lang="en">
  <head>
    <link rel="stylesheet" type="text/css" href="Acc\account.css">
    <link rel="stylesheet" type="text/css" href="Home page\home.css">
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ACCOUNT</title>
  </head>
  <body>
    <?php
      switch($_SESSION["acc"]){
        case 0: 
          if (isset($_SESSION["user"]["user_id"])&&isset($_SESSION["user"]["username"])&&isset($_SESSION["user"]["email"])) {
            $username = $_SESSION["user"]["username"];
            $email = $_SESSION["user"]["email"];
                  
            echo "<h1 class='title'>Benvenuto $username!</h1><br/>";
            echo "<h1 class='title'>Email: $email</h1><br/>";
          } 
          else {
            echo "
              <p>Siamo spiacenti ma prima devi accedere per vedere i dati del tuo account</p>
              <a href='index.php?acc=1&scelta=3' class='link'>LOGIN</a><br>
              <p>Oppure registrati se non hai ancora un account</p>
              <a href='index.php?acc=2&scelta=3' class='link'>REGISTER</a><br>
            ";
          }
        break;
        case 1: //LOGIN
          echo"
            <form action='DB\config.php' method='post' style='margin-top: 5%;' >
              <div class='container'>
                <div class='imgcontainer'>
                  <img src='Img\acc_light_blue.png' alt='Avatar' class='avatar'>
                </div>
                <label for='email'><b>EMAIL</b></label>
                <input type='email' placeholder='Enter email' name='email' id='email' required>

                <label for='psw'><b>Password</b></label>
                <input type='password' placeholder='Enter Password' name='psw' required>
                              
                <button type='submit'>Login</button>
                <button type='reset' style='background-color: #E76F51'>Cancel</button>
              </div>
            </form>";
          break;
          case 2: //REGISTER
            echo"
              <form action='DB\config.php' method='post' style='margin-top: 5%;' >
                <div class='container'>
                  <div class='imgcontainer'>
                    <img src='Img\acc_light_blue.png' alt='Avatar' class='avatar'>
                  </div>
                  <label for='username'><b>USERNAME</b></label>
                  <input type='text' placeholder='Enter username' name='username' id='username' required>

                  <label for='email'><b>EMAIL</b></label>
                  <input type='email' placeholder='Enter email' name='email' id='email' required>

                  <label for='psw'><b>Password</b></label>
                  <input type='password' placeholder='Enter Password' name='psw' id='psw' required>
                              
                  <button type='submit'>Login</button>
                  <button type='reset' style='background-color: #C62E2E'>Cancel</button>
                </div>
              </form>
            ";
          break;
      }
    ?>
  </body>
</html>