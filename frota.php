<?php
$servername = "localhost";
$database = "frota";
$username = "root";
$password = "";


$conn = mysqli_connect($servername, $username, $password, $database);


?>
<html>
    <head>
    <title>Ônibus 1</title>
        <style>
            body{
            background-color: #2e3141;
		background-image: linear-gradient(to top, rgba(46, 49, 65, 0.8), rgba(46, 49, 65, 0.8)), url("../../images/bg.jpg");
		background-size: auto, cover;
		background-attachment: fixed, fixed;
		background-position: center, center;
            }
            h1{
		color: #000000;
		font-family: Raleway, Helvetica, sans-serif;
        text-align: center;
		font-weight: 700;
		letter-spacing: 0.1em;
		margin: 20 0 50 0;
		text-transform: uppercase;
            }
             
            p{
                color: #dddddd;
		font-family: Raleway, helvetica, sans-serif;
		font-weight: 200;
		letter-spacing: 0.1em;  
		margin: 20px 0 30 0;
		text-transform: uppercase;
                    
            }
            a{
                margin: 2000 0 2000 0;
            }
        </style>
</head>
<body>
    <h1>Ônibus 1</h1>
<?php


$sql = "SELECT peso, sentido, Data_horario FROM onibus1";
$res = mysqli_query($conn, $sql);

// conta o número de registros
$total = mysqli_num_rows($res);
 


// loop pelos registros
while ($f = mysqli_fetch_array($res))
{
    
    echo  "<p>Peso: " . $f['peso'] . " Kg | Sentido do peso: " . $f['sentido'] . " | Data e horário: " . $f['Data_horario'] . "</p>" ;
    
}            
?>
    
</body>
</html>

