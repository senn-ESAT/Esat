<?php
    include("config.php");

    switch($_SESSION["scelta"]){
        case 1: // INSERISCI
            echo "
                <form action='gestione.php'>
                    <table>
                        <tr>
                            <th> <h1>Inserisci un nuovo calciatore</h1> </th>
                        </tr>

                        <tr>
                            <td><p>Cognome</p></td>
                            <td><input type='text' name='cognome'></td>
                        </tr>
                        <tr>
                            <td><p>Nome</p></td>
                            <td><input type='text' name='nome'></td>
                        </tr>
                        <tr>
                            <td><p>Età</p></td>
                            <td><input type='number' name='eta'></td>
                        </tr>
                        <tr>
                            <td><p>Squadra</p></td>
                            <td><input type='text' name='squadra'></td>
                        </tr>
                        <tr>
                            <td><p>Titolare</p></td>
                            <td><input type='checkbox' name='titolare' value='0'></td>
                        </tr>
                    </table>
                    <input type='submit'>
                </form>
            ";
        break;

        case 2: // MODIFICA
            $id = $_REQUEST["id"];
            $query = "SELECT * FROM anagrafica WHERE `anagrafica`.`idanagrafica` = $id";
            $risultato = mysqli_query($conn, $query) or die("Query Fallita");
            $dati = mysqli_fetch_assoc($risultato);
        
            echo "
                <h1>Modifica calciatore</h1>
                
                <form action='gestione.php'>
                    <table>
                        <tr>
                            <td style='text-align: left'><p>Cognome</p></td>
                            <td><input type='text' name='cognome' value=" . $dati['cognome'] . "></td>
                        </tr>
        
                        <tr>
                            <td style='text-align: left'><p>Nome</p></td>
                            <td><input type='text' name='nome' value='" . $dati['nome'] . "'></td>
                        </tr>
        
                        <tr>
                            <td style='text-align: left'><p>Età</p></td>
                            <td><input type='number' name='eta' value='" . $dati["eta"] . "'></td>
                        </tr>
        
                        <tr>
                            <td style='text-align: left'><p>Squadra</p></td>
                            <td><input type='text' name='squadra' value='" . $dati["squadra"] . "'></td>
                        </tr>
        
                        <tr>
                            <td style='text-align: left'><p>Titolare</p>
                            </td>
                            <td>";
            
            if($dati["titolare"] == 1){
                echo "<input type='checkbox' name='titolare' checked>";
            } else {
                echo "<input type='checkbox' name='titolare'>";
            }
            echo "
                            </td>
                        </tr>
                    </table>
                    <input type='submit'>
                </form>
            ";
        break;
        case 4: //ACCEDI
            echo"<form action='gestione.php'>
                    <table>
                        <tr>
                            <td><p>Mail</p></td>
                            <td><input type='text' name='mail'></td>
                        </tr>
                        <tr>
                            <td><p>Password</p></td>
                            <td><input type='text' name='password'></td>
                        </tr>
                    </table>
                    <input type='submit'>
                </form>
            ";
        break;
        case 5: // REGISTRATI
            echo "
                <form action='gestione.php'>
                    <table>
                        <tr>
                            <th> <h1>Registrati</h1> </th>
                        </tr>

                        <tr>
                            <td><p>Cognome</p></td>
                            <td><input type='text' name='cognome'></td>
                        </tr>
                        <tr>
                            <td><p>Nome</p></td>
                            <td><input type='text' name='nome'></td>
                        </tr>
                        <tr>
                            <td><p>Mail</p></td>
                            <td><input type='text' name='mail'></td>
                        </tr>
                        <tr>
                            <td><p>Password</p></td>
                            <td><input type='text' name='psw'></td>
                        </tr>
                    </table>
                    <input type='submit'>
                </form>
            ";
        break;
    }

    echo "<button><a href='index.php?scelta=0'>ANNULLA OPERAZIONE</a><button><br>";
?>