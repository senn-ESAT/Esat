//aggiunta task al calendario modale
var addpopup = document.getElementById("myModal");
var btn = document.getElementById("myBtn");

btn.onclick = function() {
  addpopup.style.display = "block";
}

window.onclick = function(event) {
  if (event.target == addpopup) {
    addpopup.style.display = "none";
  }
}