// Get the modal
// the metro
var Pmodal = document.getElementById("PolisModal");
var RLmodal = document.getElementById("RedLineModal");
var Hmodal = document.getElementById("HanzaModal");
var Rmodal = document.getElementById("ReichModal");
var Vmodal = document.getElementById("VeniceModal");
var Emodal = document.getElementById("EuropeModal");
var C05modal = document.getElementById("1905Modal");
var D6modal = document.getElementById("D6Modal");

//outside
var Moscmodal = document.getElementById("MoscowModal");
var Volgolmodal = document.getElementById("VolgaModal");
var Yamamodal = document.getElementById("YamantauModa");
var Caspmodal = document.getElementById("CaspianModal");
var Taigmodal = document.getElementById("TaigaModal");
var DCmodal = document.getElementById("DeadCityModal");
var BKmodal = document.getElementById("BaikalModal");

// Get the link Input
// the metro
var Polisbtn = document.getElementById("PBtn");
var Reichbtn = document.getElementById("RBtn");
var RedLinebtn = document.getElementById("RLBtn");
var Europebtn = document.getElementById("EBtn");
var VeniceBtn = document.getElementById("VBtn");
var HanzaBtn = document.getElementById("HBtn");
var C1905Btn = document.getElementById("C05Btn");
var d6btn = document.getElementById("D6Btn");
// outside
var Moscowbtn = document.getElementById("MoscBtn");
var Volgabtn = document.getElementById("VolgBtn");
var Yamantaubtn = document.getElementById("YamaBtn");
var Caspianbtn = document.getElementById("CaspBtn");
var TaigaBtn = document.getElementById("TaigBtn");
var DeadCityBtn = document.getElementById("DeadBtn");
var BaikaBtn = document.getElementById("BaikalBtn");

// Get the <span> element that closes the modal
var span = document.getElementsByClassName("close")[0];

// When the user clicks the button, open the modal
Polisbtn.onclick = function () {
  Pmodal.style.display = "block";
};
Reichbtn.onclick = function () {
  ReichModal.style.display = "block";
};
RedLinebtn.onclick = function () {
  RLmodal.style.display = "block";
};
Europebtn.onclick = function () {
  Emodal.style.display = "block";
};
VeniceBtn.onclick = function () {
  Vmodal.style.display = "block";
};
HanzaBtn.onclick = function () {
  Hmodal.style.display = "block";
};
C1905Btn.onclick = function () {
  c1905Modal.style.display = "block";
};
d6btn.onclick = function () {
  D6modal.style.display = "block";
};

// outside
Moscowbtn.onclick = function () {
  Moscmodal.style.display = "block";
};
Volgabtn.onclick = function () {
  Volgolmodal.style.display = "block";
};
Yamantaubtn.onclick = function () {
  Yamamodal.style.display = "block";
};
Caspianbtn.onclick = function () {
  Caspmodal.style.display = "block";
};
TaigaBtn.onclick = function () {
  Taigmodal.style.display = "block";
};
DeadCityBtn.onclick = function () {
  DCmodal.style.display = "block";
};
BaikaBtn.onclick = function () {
  BKmodal.style.display = "block";
};

span.onclick = function () {
  Pmodal.style.display = "none";
};

window.onclick = function (event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
};
