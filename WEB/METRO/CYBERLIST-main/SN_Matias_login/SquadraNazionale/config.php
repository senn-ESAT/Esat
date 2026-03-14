<?php
$host="localhost" ;
$user="root";
$psw="";
$db="dbsquadra";

$conn = @mysqli_connect($host, $user, $psw, $db);
if(mysqli_connect_errno()){
   die(mysqli_connect_error());  
}
?>