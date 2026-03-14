<?php
$root = new SimpleXMLElement('<venduto></venduto>'); //radice

// Connessione
$conn = new mysqli("localhost", "root", "", "db_aziendavda");

$nProd = $_GET['nProd'];
$query = "SELECT sum(quantitaProd) AS totaleQuantita FROM venduto WHERE ID_prod = $nProd";
$risultato = @mysqli_query($conn,$query) or die("Query fallita");

if ($riga = mysqli_fetch_assoc($risultato)) {
$totaleQuantita = $riga['totaleQuantita'];
$nuovo = $root->addChild("prodotto");
$nuovo->addAttribute("ID_prod",$nProd);
$nuovo->addChild("quantitaTot", $totaleQuantita);
}

//file_put_contents("prodVenduti.xml", $root->asXML());
Header('Content-type: text/xml');
print($root->asXML());

$conn->close();
?>
