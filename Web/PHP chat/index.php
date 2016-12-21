<!DOCTYPE html>
<html>
	<head>
		<title>Chat</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
	</head>
	<body>
		<div class="center">
			<?php session_start();
			 $connect = mysqli_connect('localhost', 'root', '', 'fisa');

			 if (isset($_POST['login']) && !empty($_POST['jmeno']))
			 {
			 	$jmeno = $_POST['jmeno'];
			 	$_SESSION['jmeno'] = $jmeno;
			 }

			 if (isset($_SESSION['jmeno']))
			 {
			 	echo "Uživatel: ".$_SESSION['jmeno']."<a href='destroy.php' style='float: right;' class='btn btn-danger'>Logout</a><br/><br/>";

			 	if (isset($_POST['message']) && !empty(($_POST['message'])))
			 	{
			 		$jmeno	= $_SESSION['jmeno'];
			 		$text	= $_POST['message'];
			 		$insert = "INSERT INTO `martin`(`jmeno`, `text`, `id`) VALUES ('$jmeno', '$text')";

			 		mysqli_query($connect, $insert);
			 		empty($_POST['message']);
			 		unset($_POST['send']);
			 	}

			 	$selection = "SELECT * FROM `martin` ORDER BY 'id' ASC";
			 	$query = mysqli_query($connect, $selection);

			 	while ($row = mysqli_fetch_array($query))
			 	{
			 		echo $row['jmeno']."napsal: ".$row['text'];
			 	}

			 ?>

				<form action="index.php" method="POST" class="form-group">
					<input type="text" name="message" class="form-control" class="form-control" placeholder="Message" />
					<input type="submit" name="send" class="btn btn-primary" />
				</form>

			<?php
			 }
			 else
			 {
		 	 ?>

			<h1>Přihlášení</h1>
			<form action="index.php" method="POST" class="form-group">
				<input type="text" name="jmeno" class="form-control" placeholder="Username" />
				<input type="submit" name="login" class="btn btn-primary" />
			</form>

			<?php
			 }
			 ?>
		</div>
	</body>
</html>