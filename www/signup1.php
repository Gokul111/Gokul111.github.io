<?php 
define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', '');
define('DB_DATABASE', 'project');

$db = mysqli_connect(DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_DATABASE);

function NewUser($db) 
{ 
    
    $name = $_POST['name'];
    $email = $_POST['email']; 
    $pass = $_POST['name1']; 
    $gender = $_POST['gender'];
    $query = mysqli_query($db,"INSERT INTO register (name,email,password,gender) VALUES ('$name','$email','$pass','$gender')") or die(mysql_error()); 
    if($query == TRUE) 
    { 
        echo "<script>
                alert('YOUR REGISTRATION IS COMPLETED..., LOGIN to Continue....');
                window.location.href='login.html';
                </script>";
    }
    else
       { echo "<script>
                alert('fail');
                window.location.href='register.html';
                </script>";
    }

} 
function SignUp($db) 
{

    if(!empty($_POST['email'])) 
    //checking the 'EMAIL' name which is from Sign-Up.html, is it empty or have some text 
    { 
        $query = mysqli_query($db,"SELECT * FROM register WHERE email = '$_POST[email]' or name = '$_POST[name]' ") or die(mysql_error()); 
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
