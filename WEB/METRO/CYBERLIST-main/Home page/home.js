// Definisci variabili per il modale
var modal = document.getElementById("myModal");
var btn = document.getElementById("acc-button");

// Mostra il modale quando il pulsante è cliccato
btn.onclick = function() {
  modal.style.display = "block";
}

// Nascondi il modale quando si clicca fuori di esso
window.onclick = function(event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
}

document.getElementById("acc-button").addEventListener("click", function() {
  var dropdown = document.getElementById("dropdown");
  dropdown.style.display = dropdown.style.display === "block" ? "none" : "block";
});

// Chiudi il dropdown se l'utente clicca al di fuori
window.onclick = function(event) {
  if (!event.target.matches('#acc-button')) {
    var dropdowns = document.getElementsByClassName("dropdown-content");
    for (var i = 0; i < dropdowns.length; i++) {
      var openDropdown = dropdowns[i];
      if (openDropdown.style.display === 'block') {
        openDropdown.style.display = 'none';
      }
    }
  }
}

//Per il meteo
function getWeather() {
  const latitude = document.getElementById('latitude').value;
  const longitude = document.getElementById('longitude').value;
    
  // API URL
  const apiURL = `https://api.open-meteo.com/v1/forecast?latitude=${latitude}&longitude=${longitude}&current_weather=true`;

  fetch(apiURL)
  .then(response => response.json())
  .then(data => {
  const currentWeather = data.current_weather;
  document.getElementById('weather-data').innerHTML = `
    <h3>Current Weather:</h3>
    <p>Temperature: ${currentWeather.temperature_2m}°C</p>
    <p>Wind Speed: ${currentWeather.wind_speed_10m} m/s</p>
    `;
  })
  .catch(error => {
    document.getElementById('weather-data').innerHTML = `<p>Error fetching weather data.</p>`;
  });
}
