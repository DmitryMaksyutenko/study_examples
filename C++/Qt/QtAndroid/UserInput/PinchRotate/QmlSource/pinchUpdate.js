function update(angle, scale) {
    greenRect.rotation = -angle;
    var nW = greenRect.width * scale;
    var nMax = Math.min(greenRect.parent.width,
                        greenRect.parent.height);
    var nMin = nMax / 2;
    greenRect.width = nW > nMax ? nMax : nW < nMin ? nMin : nW;
    greenRect.height = greenRect.width;
}
