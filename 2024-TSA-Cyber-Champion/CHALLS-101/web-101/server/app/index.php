<!DOCTYPE html>
<html>
<head>
	<title>TSA Cyber Champion</title>
	<link rel="stylesheet" type="text/css" href="assets/styles.css">
  	<link rel="stylesheet" type="text/css" href="assets/table.css">
  	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
<body>
<header>
	<ul>
		<a href="/index.php?page=index.php"><li>Home</li></a>
		<a href="/index.php?page=ping.php"><li>PING</li></a>
		<a href="/index.php?page=upload.php"><li>FileUp</li></a>
	</ul>
</header>
<section id='content'>

<?php

if (isset($_GET['page'])) {
	$page = $_GET['page'];
} else {
	$page = 'index.php';
}

include("pages/$page");

?>

</section>
<footer>
	Copyright &copy; 2024 TSA Cyber Champion
</footer>
</body>
</html>
