function onLoginSuccessful(data) {
    alert("Successfully logged in. Here is your key: " + data.ctf);
}

function onWrongPassword(error) {
    if (error.status === 403) {
        const selector = $('#wrong-password');
        selector.slideDown(300);
        setTimeout(() => selector.slideUp(300), 1500);
    } else if (error.status === 500) {
        alert("Server error: " + error.responseJSON.error);
    } else {
        alert("Something went wrong. Make sure that the server is running..");
    }

}

function onLoginClick() {
    const username = $('#username').val();
    const password = $('#password').val();
    const body = {username: username, password: password};
    const URL = 'http://localhost:8001/login';

    $.ajax({
        type: "POST",
        url: URL,
        crossOrigin: true,
        data: body,
        success: onLoginSuccessful,
        error: onWrongPassword
    });
}