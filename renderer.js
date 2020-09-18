// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.

const tableify = require("tableify");
const SerialPort = require("serialport");
const Readline = SerialPort.parsers.Readline;
const port = new SerialPort("COM22");
const parser = new Readline();
port.pipe(parser);
parser.on("data", console.log);

const btn1 = document.getElementById("saveBtn");
btn1.onclick = function changeContent() {
  const button1 = document.getElementById("button1").value;
  const button2 = document.getElementById("button2").value;
  const button3 = document.getElementById("button3").value;
  const button4 = document.getElementById("button4").value;
  port.write(`${button1},${button2},${button3},${button4}`);
};

SerialPort.list((err, ports) => {
  console.log("ports", ports);
  // if (err) {
  //   document.getElementById("error").textContent = err.message;
  //   return;
  // } else {
  //   document.getElementById("error").textContent = "";
  // }

  // if (ports.length === 0) {
  //   document.getElementById("error").textContent = "No ports discovered";
  // }

  // tableHTML = tableify(ports);
  // document.getElementById("ports").innerHTML = tableHTML;
});
