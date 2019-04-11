var express = require("express");
var http = require("http");
var app = express();
var server = http.createServer(app).listen(3000);
var io = require("socket.io")(server);
var fs = require('fs'); 
var name_of_song;
var lyr;
var temp;
var temp2;
app.use(express.static("./public"));
io.on("connection", function(socket) {

    socket.on("chat", function(message) {
    if( message == "404"){
        console.log("s5444444444444444444444444444444444444");
        fs.readFile('sn.txt', 'utf8', function(err, contents) {
            socket.broadcast.emit("me", contents);
            name_of_song=contents;
            console.log(name_of_song);
        });
        fs.readFile('ly.txt', 'utf8', function(err, contents) {
            socket.broadcast.emit("q", contents);
            lyr=contents;
            console.log(lyr);
        });
        if(temp != lyr || temp2 != name_of_song){
            socket.emit("me",name_of_song,lyr);
            console.log("yyyyyyyyyyyyyyyyyyyyyyyyyyyyy");
            if(temp != lyr){
                temp=lyr;
            }
            if(temp2 != name_of_song){
                temp2=name_of_song;
            }
        }
    }
        console.log(message);
        switch(message){
            case "1":
            fs.writeFile('dell.txt',1, function (err) {
                if (err) throw err;
                console.log('delleted');
              });break;
            case "2":
            fs.writeFile('next.txt', 1, function (err) {
                if (err) throw err;
                console.log('next');
              });break;
            case "3":
                fs.readFile('play.txt', 'utf8', function(err, contents) {
                    console.log(contents)
                    
                switch(contents){
                    case "1":
                    fs.writeFile('play.txt',0, function (err) {
                        if (err) throw err;
                        console.log('stop');
                      });break;
                    case "0":
                    fs.writeFile('play.txt',1, function (err) {
                        if (err) throw err;
                        console.log('play');
                      });break;
                };
            });break;
            case "4":
            fs.writeFile('prev.txt',1, function (err) {
                if (err) throw err;
                console.log('prev');
              });break;
        };
    });
});
console.log("Open Url - http://localhost:3000");
