<?php 
	//koneksi ke datadase
	$konek =mysqli_connect("localhost", "root", "", "websensor");

	//baca data yang dikirim oleh nodemcu
	$nilai = $_GET["sensor"];

	//update data di database (table sensor)
	mysqli_query($konek, "update sensor set nilai_sensor='$nilai'");
?>