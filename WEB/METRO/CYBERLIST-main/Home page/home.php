<!DOCTYPE html>
<html>
  <head>
    <title>CYBERPLANNER</title>
    <link rel="stylesheet" type="text/css" href="Home page\home.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400..900&display=swap" rel="stylesheet">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>      
    <!--elementi del sito-->
    <div class="elm">
      <div class="fst-line">
        <div class="nav">
          <h2 class="title">MENU</h2>
          <!--linea separazione-->
          <div class="spr-line"></div>
          <!--link menu-->
          <a href="" class="link">TO-DO</a><br>
          <a href="index.php?scelta=1" class="link">CALENDAR</a><br>
          <a href="index.php?scelta=2" class="link">ROUTINE</a><br>
          <a href="" class="link">STATS</a><br><br>
        </div><br>
        <!--roba che ti saluta-->
        <div class="stats">
          <div class="row">
            <div class="col-sm-4">
              <p><?php echo date("d/m/y"); ?></p>
            </div>
            <div class="align-self-end" style="text-align: right;">
              <p>
                <?php 
                  $hour = date("H");
                  if ($hour >= 6 && $hour < 12) {
                    echo "GOOD MORNING";
                  } elseif ($hour >= 12 && $hour < 19) {
                    echo "GOOD AFTERNOON";
                  } else {
                    echo "GOOD NIGHT";
                  }
                ?>
              </p>
            </div>
            <div class="row">
              <div class="col-sm-4"></div>
              <div class="align-self-end"style="text-align: right;">
                <span class="greeting"><?php echo $_SESSION["user"]["username"]?></span>
              </div>
            </div>
            <div class="row">
              <div class="col-sm-2">
                <div class="circle"></div>
              </div>
              <div class="col-sm-4">
                <div>
                  <span>it's</span>
                  <span>sunny</span>
                </div>
              </div>
              <div class="col align-self-end" style="text-align: right;">
                <span style="margin-right: 5%;">It's</span><br>
                <span class="greeting"><?php echo date("h:i"); ?></span>
              </div>
            </div>
          </div>
        </div>
      </div>
      <!--seconda linea elementi-->
      <div class="snd-line">
        <!--seconda immagine-->
        <div class="snd-img">
          <img src="Img/matrix.png" alt="Matrix">
        </div>

        <!--calcolo percentuale tempo-->
        <?php 
        /*giorno*/
        $currentTime = date("H") * 60 + date("i");
        $totalMinutes = 24 * 60;
        $percentageDay = ($currentTime / $totalMinutes) * 100;
        /*settimana*/
        $currentWeekDay = date("N");
        $percentageWeek = ($currentWeekDay / 7) * 100;
        /*mese*/
        $currentDay = date("j");
        $totalDaysInMonth = date("t");
        $percentageMonth = ($currentDay / $totalDaysInMonth) * 100;
        /*anno*/
        $currentDayOfYear = date("z") + 1;
        $totalDaysInYear = date("L") ? 366 : 365;
        $percentageYear = ($currentDayOfYear / $totalDaysInYear) * 100;
        ?>
    
        <!-- Tracker del tempo -->
        <div class="tm-trck"><br>
          <div class="progress" role="progressbar" aria-valuenow="<?php echo round($percentageDay, 2); ?>" aria-valuemin="0" aria-valuemax="100">
            <div class="progress-bar" style="width: <?php echo round($percentageDay, 2); ?>%"></div>
            <div class="progress-text"><?php echo round($percentageDay, 2); ?>% DAY</div>
          </div><br>
          <div class="progress" role="progressbar" aria-valuenow="<?php echo round($percentageWeek, 2); ?>" aria-valuemin="0" aria-valuemax="100">
            <div class="progress-bar" style="width: <?php echo round($percentageWeek, 2); ?>%"></div>
            <div class="progress-text"><?php echo round($percentageWeek, 2); ?>% WEEK</div>
          </div><br>
          <div class="progress" role="progressbar" aria-valuenow="<?php echo round($percentageMonth, 2); ?>" aria-valuemin="0" aria-valuemax="100">
            <div class="progress-bar" style="width: <?php echo round($percentageMonth, 2); ?>%"></div>
            <div class="progress-text"><?php echo round($percentageMonth, 2); ?>% MONTH</div>
          </div><br>
          <div class="progress" role="progressbar" aria-valuenow="<?php echo round($percentageYear, 2); ?>" aria-valuemin="0" aria-valuemax="100">
            <div class="progress-bar" style="width: <?php echo round($percentageYear, 2); ?>%"></div>
            <div class="progress-text"><?php echo round($percentageYear, 2); ?>% YEAR</div>
          </div><br>
        </div>

        <!--calendario-->
        <div class="calendar">
          <!--<iframe src="Calendar/calendarSection.html" class="calendar-frame"></iframe>-->
        </div>
      </div>

      <!--terza linea elementi-->
      <div class="trd-line">
        <!--lista routine-->
        <div class="rut-link">
          <p>asdgfaesd</p>
          <p>asdgfaesd</p>
        </div>
        <br>
        <!--immagine adattiva-->
        <div class="trd-img">
          <img src="Img/matrix.png" alt="Matrix">
        </div>
      </div>
      <!--quarta linea elementi-->
      <div class="frth-line">
        <!--musica-->
        <div class="msc">
          <p>asdgfaesd</p>
        </div>
        <br>
        <!--lista cose da fare-->
        <div class="to-do">
          <p>asdgfaesd</p>
          <p>asdgfaesd</p>
          <p>asdgfaesd</p>
          <p>asdgfaesd</p>
        </div>
        <br>
        <!--grafico a torta-->
        <div class="stts-cake">
          <p>asdgfaesd</p>
        </div><br>
      </div>
    </div>

    <h1>Weather Forecast for Verres, Aosta Valley</h1>
    
    <label for="latitude">Latitude: </label>
    <input type="text" id="latitude" value="45.7354"><br><br>
    <label for="longitude">Longitude: </label>
    <input type="text" id="longitude" value="7.6635"><br><br>
    
    <button onclick="getWeather()">Get Weather</button>
    
    
    <div id="weather-data" class="weather-container"><h1></h1></div><br>
    
    <!--javasript-->
    <script src="Home page/home.js"></script>
  </body>
</html>