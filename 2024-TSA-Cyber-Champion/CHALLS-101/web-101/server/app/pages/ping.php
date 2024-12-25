<?php

if (!empty($_POST)){
  $userInput = $_POST['input'];
  $escapedInput = escapeshellcmd(escapeshellarg($userInput));
  $output = shell_exec("ping -c 2 " . $escapedInput);

  echo '<pre style="padding-left: 20px;">' . $output . '</pre><br><br>';
}

?>

<body>
    <form style="padding-left: 20px;" method="POST" action="/index.php?page=ping.php">
      <label for="input">PING:</label>
      <input type="text" name="input" id="input" required><br>
      <button type="submit">Submit</button>
    </form>
</body>

