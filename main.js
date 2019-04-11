var socket = io("http://localhost:3000");
var play_now;
var linka;
var snd;
function updateClock() {
    var now = new Date(); // current date
    socket.emit("chat","404");
    socket.on("me", function(message,lyr) {
        document.getElementById("sn").innerHTML =message;
        if(play_now != message){
          //  alert("no "+ message);
            play_now=message;
            linka="file:///D:/data%20structure/jo/public/js/"+play_now;
            sound= new Audio(linka);
        }
        document.getElementById("ly").innerHTML =lyr;
    });
    setTimeout(updateClock, 1000);
}
updateClock()


//alert("fuck up"+linka);

document.forms[0].onsubmit = function del() {
};
document.forms[0].onsubmit = function next() {
};
document.forms[0].onsubmit = function playb() {
};
document.forms[0].onsubmit = function prev() {
};

function del() {
 //   alert("dell");
    sound.pause();
    socket.emit("chat","1");
};

function next() {
 ///   alert("next");
    sound.pause();
    socket.emit("chat","2");
};
var temp=0;
alert(play_now);


function playb() {
   // alert("play");
    sound.type = 'audio/wav';
    socket.emit("chat","3");
    switch(temp){
        case 0:temp=1;break;
        default:temp=0;
    }

    if(temp == 0){
       // alert("stop");

        sound.pause();
    }else{
  //      alert("i will play:"+linka);
        sound.play();
    }
};

function prev() {
 ///   alert("prev");
    sound.pause();
    socket.emit("chat","4");
};

