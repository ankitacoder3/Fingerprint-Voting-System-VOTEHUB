var http = require('http');
var url = require('url');
var fs = require('fs');
var path = require('path');

const fileTypes = {
    'html': 'text/html',
    'css': 'text/css',
    'js': 'text/javascript',
    'png': 'image/png',
    'jpeg': 'image/jpeg',
    'jpg': 'image/jpg',
    'jfif': 'image/jfif'
};



http.createServer((request, response) => {
    var myurl = url.parse(request.url).pathname;
    var fileName = path.join(process.cwd(), unescape(myurl));
    console.log('File that is opened is:' + fileName);
    var loadedFile;

    try {
        loadedFile = fs.lstatSync(fileName);
    } catch (error) {
        response.writeHead(404, {
            "Content-Type": 'text/plain'
        });
        response.write('404: Internal Error');
        response.end();
        return;
    }

    if (loadedFile.isFile()) {
        var fileType = fileTypes[path.extname(fileName).split('.').reverse()[0]];
        response.writeHead(200, {
            "Content-Type": fileType
        });
        var fileStream = fs.createReadStream(fileName);
        fileStream.pipe(response);
    } else if (loadedFile.isDirectory()) {
        response.writeHead(302, {
            'Location': 'introduction.html'
        });
        response.end();
    } else {
        response.writeHead(500, {
            "Content-Type": 'text/plain'
        });
        response.write('500: Internal Error');
        console.log("");
        response.end();
    }

}).listen(8081, () => {
    console.log('Server is running on server http://localhost:8081');
});
