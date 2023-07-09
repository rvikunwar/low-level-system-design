let count = 0;
let instance = null;


function delay(sec){
    return new Promise((resolve)=>{
        setTimeout(()=>{
            console.log(`delay of ${sec} seconds`)
            resolve()
        }, [sec*1000])
    })
}

class Singleton {
    constructor(){
        if(instance instanceof Singleton){
            return instance;
        }
    }

    static async getInstance(time){
        if(instance == null){
            await delay(time)
            count++;
            instance = new Singleton();
        }
        return instance
    }
}

// (async ()=>{
//     const instance1 = await Singleton.getInstance(2);
//     console.log(1)
//     const instance2 = await Singleton.getInstance(4);
//     console.log(2)

//     console.log(instance1 instanceof Singleton); // true
//     console.log(instance2 instanceof Singleton); // true
//     console.log(instance1 === instance2); // true
// })()

// const http = require('http')

// const server = http.createServer(
//     async (_, res)=>{
//         console.log("Request recieved !!")
//         await delay(3);
//         res.end("Hello world !!")
//     });
// server.listen(3000)
// console.log("Server listening at 3000")