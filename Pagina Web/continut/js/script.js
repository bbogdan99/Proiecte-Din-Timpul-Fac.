let d = new Date();
let os = navigator.platform;
//let v = navigator.vendor;

let v = window.location.href;

let data = new Date();
let Zi = data.getDay();
let Luna = data.getMonth();
let An = data.getFullYear();

//document.body.innerHTML = "<h1>Data este " + d + " sistemul de operare este " + os + " browser-ul este " + v + "</h1>"
function Data()
{
    document.getElementById("DataCurenta").innerHTML = "Data este: " + Zi + "/" + Luna + "/" + An + "<br>"
}

function Ora()
{
    setInterval(OraS, 1000);
}
function OraS()
{
    const data = new Date();
    document.getElementById("Ora").innerHTML = "Ora curenta este " +  data.toLocaleTimeString() + "<br>";
}

function Adresa()
{
    document.getElementById("AdresaCurenta").innerHTML = "Adresa curenta este: " + v +  "<br>";
}

function Locatie()
{
    if (navigator.geolocation)
    {
        navigator.geolocation.getCurrentPosition(showPosition);
    }   
    else document.getElementById("Locatie").innerHTML = "Eroare"
}

function showPosition(position)
{
    document.getElementById("Locatie").innerHTML = "Latitudine: " + position.coords.latitude + "<br>Longitude: " + position.coords.longitude + "<br>";
}

function Browser()
{
    let browser = navigator.userAgent;

    if (browser.match(/chrome/i))
        document.getElementById("Browser").innerHTML = "Chrome";
    else if(browser.match(/firefox/i))
        document.getElementyById("Browser").innerHTML = "Firefox";
    else if(userAgent.match(/safari/i))
        document.getElementyById("Browser").innerHTML = "Safari";
    else if(userAgent.match(/opr/i))
        document.getElementyById("Browser").innerHTML = "Opera";
    else if(userAgent.match(/edg/i))
        document.getElementyById("Browser").innerHTML = "Edge";
}

function OS()
{
    let sistem = "Neidentificat";
    if (os.charAt(0) == "W")
        sistem = "Windows";
    if (os.charAt(0) == "M")
        sistem = "MacOS";
    if (os.charAt(0) == "L")
        sistem = "Linux";
    document.getElementById("OS").innerHTML = "Sistemul de operare este " + sistem + "<br>";
}

function getMousePosition(canvas, event)
{
    let rect = canvas.getBoundingClientRect();
    let x = event.clientX - rect.left;
    let y = event.clientY - rect.top;

    document.getElementById("test").innerHTML = x + " " + y + "<br>";

}



let canvasElem = document.querySelector("canvas");
canvasElem.addEventListener("mousedown", function(e)
{
    getMousePosition(canvasElem, e);
});

function creeazaCelula(text, culoare)
{
    let element = document.createElement("td");
    element.style.backgroundColor = culoare;
    element.innerText = text;

    return element;
}

function creeazaTabelLinie()
{
    let tabel = document.getElementById("tabel");

    if(tabel.childNodes.length == 0)
    {
        let row = document.createElement("tr");
        row.appendChild(creeazaCelula("Linie", document.getElementById("tabelculoare").value));
        tabel.appendChild(row);
    }
    else
    {
        let row = document.createElement("tr");
        for(let i = 0; i < tabel.childNodes[0].childNodes.length; i++)
            row.appendChild(creeazaCelula("Linie", document.getElementById("tabelculoare").value));
        tabel.insertBefore(row, tabel.childNodes[document.getElementById("tabelnumar").value]);
    }
}

function creeazaTabelColoana()
{

    let tabel = document.getElementById("tabel");

    if(tabel.childNodes.length == 0)
    {
        let row = document.createElement("tr");
        row.appendChild(creeazaCelula("Coloana", document.getElementById("tabelculoare").value));
        tabel.appendChild(row);
    }
    else
    {
        for(let i = 0; i < tabel.childNodes.length; i++)
            tabel.childNodes[i].insertBefore(creeazaCelula("Coloana", document.getElementById("tabelculoare").value), tabel.childNodes[i].childNodes[document.getElementById("tabelnumar").value]);
    }
}
