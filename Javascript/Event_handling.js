
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>exHandling</title>

    <script>
        function tryexcp() {
            const er = document.getElementById("display");
            er.innerHTML = "";
            let name = document.getElementById("name").value;
            let email = document.getElementById("email").value;
            try {
                if (name.length > 5) throw "Invalid Name";
                if (email == "@gmail.com") throw "Invalid Email";
            }
            catch (err) {
                alert("caught error");
                er.innerHTML = new Error("Problem Occured");
            }
            finally {
                document.getElementById("final").innerHTML = "Thank You";
            }
        }
    </script>
</head>

<body>

    <br><br><br>
    <div>
        <h2>Practical 2: </h2>
        <h3>Write a JS code to implement the following logic using event Handling</h3>
        <h4 id="display"> </h4>
        <br><br><br>
        <center>
            <form action="">
                <label for="name">Name: </label>
                <input type="text" name="name" id="name">
                <br> <br><br>
                <label for="email">Email:</label>
                <input type="email" name="email" id="email">
                <br><br><br>
                <button type="button" onclick="tryexcp()">SUBMIT</button>
            </form>
            <h2 id="final"></h2>
    </div>
    </center>
</body>

</html>
