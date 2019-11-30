document.write('<p style="text-align: center; font-size: 26px; color: red;">Arrays and Objects as propersties.</p>')

function Tree(rank, refs, number, code){
  this.rank = rank
  this.number = number || 1
  this.code = code || "| "
  this.code += this.rank +" -> "+ this.number +"| "

  if (this.rank > 1){
    this.next = new Array(refs)

    for (let i = 0; i < this.next.length; i++){
      this.next[i] = new Tree(this.rank - 1, refs, i + 1, this.code)
    }
  }
}

Tree.prototype.toString = function(){
  let t = "<p style='text-align: center;'>Object rank = "+ this.rank +", number = "+ this.number
  t += ", code = "+ this.code +"</p>"

  if (this.rank > 1){
    for (let i = 0; i < this.next.length; i++){
      t += this.next[i].toString()
    }
  }

  return t
}

var myTree = new Tree(4, 2)

document.write(myTree)

document.write('<hr>')
