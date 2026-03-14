<?php
$nProd = $_GET["nProd"];
$xml = file_get_contents("http://localhost/DBVdaAzienda/vconclient/transXML.php?nProd=".$nProd);
file_put_contents("prodVenduti.xml", $xml);
$object = simplexml_load_file("prodVenduti.xml");
echo "Prodotto venduto ". $object->prodotto->quantitaTot ." volte";
?>