var PORT = 33333;
var HOST = '192.168.2.1';
var tessel = require('tessel')

var dgram = require('dgram');
var server = dgram.createSocket('udp4');

server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

server.on('message', function (message, remote) {
    console.log(remote.address + ':' + remote.port +' - ' + message);

});

server.bind(PORT, HOST);

var Photon = '192.168.2.100';

var message = new Buffer('My KungFu is Good!');

var client2 = dgram.createSocket('udp4');
client2.send(message, 0, message.length, PORT, Photon, function(err, bytes) {
    if (err) throw err;
    console.log('UDP message sent to ' + HOST +':'+ PORT);
    client2.close();
});