const http=require('http')
const fs=require('fs')
const x2j = require('xml2js')

const server=http.createServer((req,res)=>
{
    const data=fs.readFile('data.xml',(error,contents)=>
    {
        let pa = new x2j.Parser();
        pa.parseString(contents.toString(),(err,result)=>
        {
            result.libr.name.forEach(name => {
                res.write(name + "\n");
             });
            res.end();
        });
    });
});
server.listen(2000,()=>{console.log("Running at Port 2000")});