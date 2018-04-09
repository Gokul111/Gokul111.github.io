<?php 
define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', '');
define('DB_DATABASE', 'project');

$db = mysqli_connect(DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_DATABASE) or die("Failed to connect to MySQL DATABASE: " . mysql_error());

function NewUser($db) 
{ 
    $name = $_POST['name'];
    $pass = $_POST['name1']; 
    $gender = $_POST['name3'];
    $query = mysqli_query($db,"INSERT INTO register (name,password,gender) VALUES ('$name','$pass','$gender')") or die(mysql_error()); 
    if($query == TRUE) 
    { 
        echo "<script>
                alert('YOUR REGISTRATION IS COMPLETED...');
                window.location.href='login.html';
                </script>";
    }
} 
function SignUp($db) 
{ 
    if(!empty($_POST['name'])) 
    //checking the 'user' name which is from Sign-Up.html, is it empty or have some text 
    { 
        $query = mysqli_query($db,"SELECT * FROM register WHERE name = '$_POST[name]' AND password = '$_POST[password]'") or die(mysql_error()); 
        if(!$row = mysqli_fetch_array($query))
        {
             newuser($db); 
        } 
        else 
        {  
            echo "<script>
                alert('THIS USERNAME IS ALREADY TAKEN...');
                window.location.href='register.html';
                </script>";
        } 
    } 
} 
if(isset($_POST['submit'])) { SignUp($db); } ?>
