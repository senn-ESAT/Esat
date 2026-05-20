// Get the modal
// the metro
var Pmodal = document.getElementById("PolisModal");
var RLmodal = document.getElementById("RedLineModal");
var Hmodal = document.getElementById("HanzaModal");
var Rmodal = document.getElementById("ReichModal");
var Vmodal = document.getElementById("VeniceModal");
var Emodal = document.getElementById("EuropeModal");
var C05modal = document.getElementById("c1905Modal");
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
var Reichbtns = document.querySelectorAll(".RBtn");
var RedLinebtns = document.querySelectorAll(".RLBtn");
var Europebtn = document.getElementById("EBtn");
var VeniceBtns = document.querySelectorAll(".VBtn");
var HanzaBtn = document.getElementById("HBtn");
var C1905Btns = document.querySelectorAll(".C05Btn");
var d6btn = document.getElementById("D6Btn");
// outside
var Moscowbtn = document.getElementById("MoscBtn");
var Volgabtn = document.getElementById("VolgBtn");
var Yamantaubtn = document.getElementById("YamaBtn");
var Caspianbtn = document.getElementById("CaspBtn");
var TaigaBtn = document.getElementById("TaigBtn");
var DeadCityBtn = document.getElementById("DeadBtn");
var BaikaBtn = document.getElementById("BaikalBtn");

document.querySelectorAll("map area").forEach(function (area) {
  area.addEventListener("click", function (event) {
    if (event && event.preventDefault) {
      event.preventDefault();
    }
  });
});

// Get the <span> element that closes the modal
var span = document.getElementsByClassName("close")[0];

// When the user clicks the button, open the modal
Polisbtn.onclick = function (event) {
  if (event && event.preventDefault) event.preventDefault();
  Pmodal.style.display = "block";
};
Reichbtns.forEach(function (btn) {
  btn.onclick = function (event) {
    if (event && event.preventDefault) event.preventDefault();
    Rmodal.style.display = "block";
  };
});
RedLinebtns.forEach(function (btn) {
  btn.onclick = function (event) {
    if (event && event.preventDefault) event.preventDefault();
    RLmodal.style.display = "block";
  };
});
Europebtn.onclick = function (event) {
  if (event && event.preventDefault) event.preventDefault();
  Emodal.style.display = "block";
};
VeniceBtns.forEach(function (btn) {
  btn.onclick = function (event) {
    if (event && event.preventDefault) event.preventDefault();
    Vmodal.style.display = "block";
  };
});
HanzaBtn.onclick = function (event) {
  if (event && event.preventDefault) event.preventDefault();
  Hmodal.style.display = "block";
};
C1905Btns.forEach(function (btn) {
  btn.onclick = function (event) {
    if (event && event.preventDefault) event.preventDefault();
    C05modal.style.display = "block";
  };
});
d6btn.onclick = function (event) {
  if (event && event.preventDefault) event.preventDefault();
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
