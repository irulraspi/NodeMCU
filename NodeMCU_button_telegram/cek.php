<?php
define("HOSTNAME", "localhost");
define("USERNAME", "root");
define("PASSWORD", "M3m0ry123");
define("DATABASE", "mmr_mis");
$connect=new mysqli(HOSTNAME,USERNAME,PASSWORD,DATABASE) or die("database error or connection error");

$status = $_GET['status_log'];
$plant = $_GET['plant'];
$machine_assetcode = $_GET['kode_mesin'];

$sqlView = "SELECT * FROM log_machine_activity where machine_assetcode='$machine_assetcode' ORDER BY date_log DESC LIMIT 1;";
$resultView = mysqli_query($connect, $sqlView);
$row = mysqli_fetch_array($resultView, MYSQLI_ASSOC);
$status_log = $row['status_log'];

?>