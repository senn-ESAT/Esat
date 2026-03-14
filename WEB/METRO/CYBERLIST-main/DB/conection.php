<?php
  $host="localhost";
  $user="root";
  $psw="";
  $db="cyberplanner";
  /* Connessione e selezione del database */
  $conn = mysqli_connect($host, $user, $psw, $db);
  if(mysqli_connect_errno()){
    die(mysqli_connect_error());  //stampa errore e ferma lo script
  }