// 1) Create a single segment.
// 2) The source segment are parting in three equivalent parts. On the base of the central segment creates the Equilateral triangle, after that dele the central segment.
// 3) The next step is a division of each segment into three equivalent parts. All central parts are the base for an equilateral triangle.
// 4) Repeat the third step in the indicated quantity.

var cnv, ctx, sel

function getPoints(a, b){

    var p, k, i, j, phi
    var pts = new Array(2)

    // start points.
    for(i = 0; i < pts.length; i++){
        pts[i] = new Array(2)
    }

    // start coordinates.
    for(i = 0; i < 2; i++){
         pts[0][i] = a[i]
         pts[1][i] = b[i]
    }

    // get counter.
    var n = document.getElementById("count").selectedIndex

    // calculation for points.
    for(k = 1; k <= n; k++){
        p = new Array(4 * pts.length - 3) // container for new points.

        // get points.
        for(i = 0; i < pts.length - 1; i++){
            for(j = 0; j < 4; j++){
                p[4 * i + j] = new Array(2)
            }

            // get coordinates.
            for(j = 0; j < 2; j++){
                p[4 * i][j] = pts[i][j]
                p[4 * i + 1][j] = Math.round(2 * pts[i][j] / 3 + pts[i + 1][j] / 3)
                p[4 * i + 3][j] = Math.round(pts[i][j] / 3 + 2 * pts[i + 1][j] / 3)
            }

            //  angle between straigth and coordinate axis.
            phi = Math.atan2(p[4 * i + 1][1] -p[4 * i + 3][1], p[4 * i + 3][0] -p[4 * i + 1][0])

            var L = Math.sqrt(Math.pow(p[4 * i + 3][0] - p[4 * i + 1][0], 2) + Math.pow(p[4* i + 3][1] - p[4 * i + 1][1], 2))

            p[4 * i + 2][0] = Math.round(p[4 * i + 1][0] + L * Math.cos(phi + Math.PI / 3))
            p[4 * i + 2][1] = Math.round(p[4 * i + 1][1] - L * Math.sin(phi + Math.PI / 3))

        }

        p[4 * pts.length - 4] = new Array(2)

        for(j = 0; j < 2; j++){
            p[4 * pts.length - 4][j] = pts[pts.length - 1][j]
        }

        pts = p
    }

    return pts

}

function drawPoints(p, ct){

    ct.beginPath()
    ct.strokeStyle = "blue"
    ct.lineWidth = 1
    ct.moveTo(p[0][0], p[0][1])

    for(let i = 1; i < p.length; i++){
        ct.lineTo(p[i][0], p[i][1])
    }

    ct.stroke()

}

window.onload = function(){

    cnv = document.getElementById("showflake")
    ctx = cnv.getContext("2d")
    sel = document.getElementById("count")
    var k , nMax = 9

    for(k = 0; k <= nMax; k++){
        sel.options[k] = new Option(k , k)
        sel.selectedIndex = 0
    }

    drawPoints(getPoints([10, cnv.height - 10], [cnv.width - 10, cnv.height - 10]), ctx)
    sel.onchange = function(){
        ctx.clearRect(0, 0, cnv.width, cnv.height)
        drawPoints(getPoints([10, cnv.height - 10], [cnv.width - 10, cnv.height - 10]), ctx)
    }

}