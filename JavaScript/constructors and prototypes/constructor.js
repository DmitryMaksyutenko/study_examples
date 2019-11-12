//  The object constructor.
document.write('<h1 style="text-align:center; color:red; font-size:26;">The object constructor</1h>')
document.write('<hr>')

//  The function prototye
var A = new MyObject("A object", 1000)
var B = new MyObject("B object", 2000)

A.show()
B.show()

MyObject.prototype.color = "red"

A.show()
B.show()

document.write('<hr>')

function MyObject(name, number){
    this.name = name
    this.number = number

    this.show = function(){
        for (var i in this){
            if (i != "show"){
                document.write(i + " -> " + this[i] + " | ")
            }
        }
        document.write("<br>")
    }
}

