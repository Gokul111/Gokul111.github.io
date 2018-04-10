<?php
   
   include("session.php");
   
   if($_SERVER["REQUEST_METHOD"] == "POST") {
      // username and password sent from form 
      
      $myusername = mysqli_real_escape_string($db,$_POST['name']);
      $mypassword = mysqli_real_escape_string($db,$_POST['name1']); 
      $sql = "SELECT email FROM register WHERE email = '$myusername' and password = '$mypassword' ";
      $result = mysqli_query($db,$sql) or die(mysql_error());
      $row = mysqli_fetch_array($result,MYSQLI_ASSOC);
      
      $count = mysqli_num_rows($result);
      
      if($count == 1) {
         $_SESSION['login_user'] = $myusername;
         echo "<script>
                window.location.href='loggedin.php';
                </script>";
      }else {
        echo "<script>
                alert('Your Login Name or Password is invalid');
                window.location.href='login.html';
                </script>";
      }
   }
?>