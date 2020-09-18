// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.
const SerialPort = require("serialport");
const Readline = SerialPort.parsers.Readline;
let port;
let parser;

const setPort = (selectedPort) => {
  console.log("Selected port --->", selectedPort);
  port = new SerialPort(selectedPort);
  parser = new Readline();
  port.pipe(parser);
  parser.on("data", console.log);
};

SerialPort.list((err, ports) => {
  console.log("ports", ports);
  const portsList = document.getElementById("ports");

  for (let i = 0; i < ports.length; i++) {
    portsList.add(
      new Option(
        `${ports[i].comName} - ${ports[i].manufacturer}`,
        ports[i].comName,
        i === 0
      )
    );
  }

  setPort(portsList.options[portsList.selectedIndex].value);

  portsList.addEventListener("change", function () {
    setPort(this.value);
  });

  const btn1 = document.getElementById("saveBtn");
  btn1.onclick = function changeContent() {
    const button1 = document.getElementById("button1").value;
    const button2 = document.getElementById("button2").value;
    const button3 = document.getElementById("button3").value;
    const button4 = document.getElementById("button4").value;
    port.write(`${button1},${button2},${button3},${button4}`);
  };
});
