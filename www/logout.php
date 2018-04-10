<?php
   session_start();
   
   if(session_destroy()) {
      header("Location: kerala-overview1.php");
   }
?>