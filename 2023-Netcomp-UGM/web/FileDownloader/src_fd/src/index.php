<style>

body{
    background-color: #F9A826;
}

.rows{
    height: 100vh;
}

.form-control {
    display: block;
    width: 100%;
    min-height: calc(1.5em + .75rem + 2px);
    padding: .575rem .75rem;
    font-size: 1rem;
    font-weight: 400;
    line-height: 1.5;
    color: #495057;
    background-color: #fff;
    background-clip: padding-box;
    border: 1px solid #ced4da;
    -webkit-appearance: none;
    -moz-appearance: none;
    appearance: none;
    border-radius: 52px;
    transition: border-color .15s ease-in-out,box-shadow .15s ease-in-out;
}

.card{
    padding: 20px;
    background-color: #eee;
    padding-bottom: 50px;
    padding-top: 50px;
}

.form-control:focus {
    color: #495057;
    background-color: #fff;
    border-color: #f9a826;
    outline: 0;
    box-shadow: none;
}

.border-rad{
    border-top-right-radius: 28px;
    border-bottom-right-radius: 28px;

    color: #fff;
    background-color: #f9a826;
    border-color: #f9a826;
}

.border-rad:hover{
    background-color: #f9a826;
    border-color: #f9a826;
}
</style>

<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha1/dist/css/bootstrap.min.css">

<form action="/download.php" method="POST">
    <div class="row d-flex justify-content-center align-items-center rows">
        <div class="col-md-6">
            <div class="card">
                <div class="text-center">
                    <img src="https://img.freepik.com/premium-vector/download-vector-illustration-file-download-50-percent-internet-graph-with-load-text-download-arrow-cloud-storage-loading-concept-vector-black-line-icon-white-background_748571-116.jpg" width="200">
                    <span class="d-block mt-3">Free file downloader via url (LIMIT FOR 2KB FILE) </span>
                    <div class="mx-5">
                        <div class="input-group mb-3 mt-4">
                            <input type="text" class="form-control" name="url" placeholder="Enter url" aria-label="" aria-describedby="button-addon2">
                            <button class="btn btn-success border-rad" type="submit" id="button-addon2">Download</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</form>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha1/dist/js/bootstrap.bundle.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>