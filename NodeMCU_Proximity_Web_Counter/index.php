<!DOCTYPE html>
<html>
<head>

  <meta charset="uts-8">  
  <meta nama="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
  
  <script type="text/javascript" src="jquery/jquery.min.js"></script> 
  <title>Web Sensor Realtime</title>
  <script type="text/javascript">
    $(document).ready(function(){
      setInterval(function(){
        $("#ceksensor").load('ceksensor.php');
      },1000);
    });
   
  </script>

  <style type="text/css">
   @font-face {
         font-family: "Font Digital";
         src: url('digital-7.ttf');
         }
 
   .digital {
         font-family: "Font Digital";
         font-weight: bold;

         }

    h1 {

        font-size: 200px;
        }    
    h2 {

        font-size: 70px;
        }   
  </style>       

</head>
<body>
 
  <div class="container" style="text-align: center; padding-top: 2%; width: 500px">
    <h2 class="digital"><font color="blue">COUNTER SENSOR</font></h2>

    <div class="panel panel-default" style="background-color:black">
      <div class="panel-body">
        <h1 class="digital" ><font color="red"><span id="ceksensor"></span></font></h1>       
      </div>
    </div>
    
       <img src="images/harin.png">
  </div>
 </body>
</html>