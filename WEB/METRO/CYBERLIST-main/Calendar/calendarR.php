<!DOCTYPE html>
<html>
<head>
  <title>CYBERPLANNER</title>
  <link rel="stylesheet" type="text/css" href="Calendar\calendarR.css">
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400..900&display=swap" rel="stylesheet">
<body>
  <div class="elm">
    <div class="txt">TO-DO LIST</div>
    <button id="myBtn"> + </button>
    <div id="myModal" class="modal">
      <div id="event-section" class="eventSection">
        <h3>Add Event</h3>
        <input type="date" id="eventDate">
        <input type="text" id="eventTitle" placeholder="Event Title">
        <input type="text" id="eventDescription" placeholder="Event Description">
        <button id="addEvent" onclick="addEvent()">Add</button>
      </div>
    </div>
  </div>

  <div class="spr-line"></div>

  <div class="elm">
    <div class="lines">
      <img src="Img/matrix.png" alt="Matrix" class="small_img">
      <div id="reminder-section">
        <ul id="reminderList">
          <li data-event-id="1">
            <strong>Event Title</strong> - Event Description on Event Date
            <button class="delete-event" onclick="deleteEvent(1)">Delete</button>
          </li>
        </ul>
      </div>
    </div>
  </div><br>

  <div class="elm">
    <div class="txt">CALENDAR</div>
  </div>

  <div class="spr-line"></div>

  <div class="elm">
    <div class="calendar-line">
      <div class="container-calendar">
        <!-- Includi la parte separata del calendario -->
        <?php include 'calendarSection.html'; ?>
      </div>
    </div>
  </div>
  <!-- Carica il file JavaScript qui -->
  <script src="Calendar\calendar.js" defer></script>
</body>
</html>