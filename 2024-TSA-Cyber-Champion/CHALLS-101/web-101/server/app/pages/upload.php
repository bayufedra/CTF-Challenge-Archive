<?php

if (!empty($_POST)){
    $imgs = basename($_FILES["image"]["name"]);

    $target_dir = "uploads/";
    $target_file = $target_dir . md5($imgs) . '.jpg';

    $check = getimagesize($_FILES["image"]["tmp_name"]);
    if($check !== false) {
        $uploadOk = 1;
    } else {
        $uploadOk = 0;
    }

    if (file_exists($target_file)) {
        $uploadOk = 0;
    }

    if ($_FILES["image"]["size"] > 100000) {
        $uploadOk = 0;
    }

    if ($uploadOk == 1) {
        move_uploaded_file($_FILES["image"]["tmp_name"], $target_file);

        $url = 'http://' . $_SERVER['HTTP_HOST'] . '/' . $target_file;
        echo '<center>';
        echo 'Image Successfully uploaded!';
        echo '<br>';
        echo "$url";
        echo '</center>';
    }
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
  <title>LKS Image Storage</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
</head>
<body>

<div class="container">
  <form action="<?php echo $_SERVER["PHP_SELF"];?>?page=upload.php" method="post" enctype="multipart/form-data">
    <div class="form-group">
      <label for="image">Upload your Image</label>
      <input type="file" name="image" class="form-control-file" id="image">
    </div>
    <button type="submit" name="submit" class="btn btn-default">submit</button>
  </form>
</div>

</body>
</html>
