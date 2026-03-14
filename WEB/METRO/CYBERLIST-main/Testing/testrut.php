<!DOCTYPE html>
<!--madel aggiunta rout-->
<html>
<head>
  <title>CYBERPLANNER</title>
  <link rel="stylesheet" type="text/css" href="Testing/testrut.css">
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400..900&display=swap" rel="stylesheet">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    
  <div class="addrtnbtnttl">
    <div class="txt">ROUTINE</div>
    <button id="myBtn"> + </button>
  </div>

  <div class="spr-line"></div>

  <!--foto e "calendario" con eventi della routine-->
  <div class="elm-rut">
    <div class="img-div">
      <img src="../Img/matrix.png" alt="Matrix">
    </div>
    <!--display timeline routine-->
    <div class="rut-div">

    </div>
  </div>
    
  <!--crea nuova task-->
  <div id="myModal" class="addpopup">
    <div id="addbtn-content">
      <h1>New Habit</h1>
      <!--impostazione dei tempi-->
      <div class="strthr">
      <!--Ora di inizio-->
      <p id="gd">Start:</p>
      <input type="time" id="hrslct">
      <!--Ora di fine-->
      <p id="gd">End:</p>
      <input type="time" id="hrslct">
    </div>
      
    <!--impostazione del giorno-->
    <div class="dayslct">
      <p id="gd">Select a day:</p>
      <select id="daylst">
        <option>MONDAY</option>
        <option>TUESDAY</option>
        <option>WEDNESDAY</option>
        <option>THURSDAY</option>
        <option>FRIDAY</option>
        <option>SATURDAY</option>
        <option>SUNDAY</option>
        <option>EVERYDAY</option>
      </select>
    </div>

    <div class="description">
      <p id="gd">Insert a desctiption:</p>
      <input type="text" id="dscr-act">
    </div>
    <!--tasto creazione-->
    <button id="AddBlock">Add New Task</button>
  </div>

  <script src="Testing/testrut.js" defer></script>
</body>
</html>