<!DOCTYPE html>
<html lang="it">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>La mia nazionale</title>
        <link href="stili.css" rel="stylesheet">
    </head>
    <body>
        <div class="contFoto">
            <h1 class="imgTxt"><b>LA MIA NAZIONALE</b></h1>
            <img src="img/nazionale.jpg" class="img">
        </div>
        <div class="contenitore">
        <?php   
            session_start();
            include("config.php");

            if(isset($_REQUEST["scelta"])){
                $_SESSION["scelta"] = $_REQUEST["scelta"];
            }
            else{$_SESSION["scelta"] = 0;}

            if(isset($_REQUEST["id"])){
                $_SESSION["id"] = $_REQUEST["id"];
            }
            else{$_SESSION["id"] = -1;}
    

            switch($_SESSION["scelta"]){
                case 0: //squadra
                    $query = "SELECT * FROM anagrafica";
                    $risultato = @mysqli_query($conn, $query) or die("Query fallita");
                    $n_righe = @mysqli_num_rows($risultato);

                    $risUtente = 0;
                    echo "
                        <table>
                            <tr>
                                <td colspan=\"6\">";
                                    if($_SESSION['risUtente'] == 1){                                    
                                        echo "<button><a href='index.php?scelta=1'>INSERISCI</a></button>";
                                        echo "<button><a href='index.php?scelta=6'>LOGOUT</a></button>";
                                    }
                                echo "
                                </td>
                                <td>
                                ";
                                    if($_SESSION['risUtente'] == 0){
                                        echo "
                                        <button><a href='index.php?scelta=4'>ACCEDI</a></button></td>
                                        <td><button><a href='index.php?scelta=5'>REGISTRATI</a></button></td>
                                        ";
                                    }
                                    else{
                                        echo "<p>Benvenuto</p>";
                                    }
                                echo "
                                </td>
                            </tr>

                            <tr>
                                <th>ID</th>
                                <th>Cognome</th>
                                <th>Nome</th>
                                <th>Età</th>
                                <th>Squadra</th>
                                <th>Titolare</th>
                            </tr>
                        ";
                        while($riga = mysqli_fetch_array($risultato, MYSQLI_NUM)) {
                            echo "<tr>";
                            $id = $riga[0];
        
                            for($i = 0; $i < sizeof($riga); $i++){
                                echo "<td>";

                                if($i == 5){
                                    if($riga[$i] == 0){
                                        echo "No";
                                    }
                                    else{
                                        echo "Si";
                                    }
                                }
                                else{
                                    echo $riga[$i];
                                }
                                echo "</td>";
                            }
        
                            echo "
                                <td>";
                                if($_SESSION['risUtente'] == 1){
                                    echo"
                                    <button><a href='index.php?scelta=2&id=$id'>MODIFICA</a><button>
                                    <td><button><a href='index.php?scelta=3&id=$id'>ELIMINA</a><button>";
                                }
                                echo"
                                </td>
                                </tr>
                            ";
                        }
                        echo"</table>";
                    break;

                    case 1: //INSERISCI
                        include("form.php");
                    break;

                    case 2: //MODIFICA
                        include("form.php");
                    break;

                    case 3: //ELIMINA
                        include("gestione.php");
                    break;

                    case 4: //ACCEDI
                        include("form.php");
                    break;

                    case 5: //REGISTRATI
                        include("form.php");
                    break;
                    case 6: // LOGOUT
                        $_SESSION['risUtente'] = 0;
                        header("Location: index.php");
                        exit;
                    break;
                }
            ?>
        </div>
        <div class="footer">
            <p>&copy; Copyright di Matias Senn <?php echo date("Y"); ?></p>
        </div>
    </body>
</html>