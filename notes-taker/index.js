const title = document.getElementById('title');
const note = document.getElementById('note');
const addBtn = document.getElementById('addBtn');
const search = document.getElementById('searchNote');
const searchBtn = document.getElementById('searchBtn');

const getItem = () => {
    let notes = localStorage.getItem('notes');
    if (notes === null) {
        notesObj = [];
    }
    else {
        notesObj = JSON.parse(notes);
    }
}

const deleteNote = (index) => {
    getItem();
    notesObj.splice(index, 1);
    localStorage.setItem('notes', JSON.stringify(notesObj));
    displayNotes();
}

const displayNotes = () => {
    getItem();
    let notesCode = ``;
    notesObj.forEach((element, index) => {
        notesCode += `
        <div class="noteCard my-2 mx-2 card">
            <div class="card-body" style="max-width: 32rem;">
                <h5 class="card-title">${element.title}</h5>
                <p class="card-text"> ${element.text}</p>
                <button id="${index}"onclick="deleteNote(this.id)" class="btn btn-primary">Delete Note</button>
            </div>
        </div>
        `
    });
    let notesElement = document.getElementById('notes')
    if (notesObj.length != 0) {
        notesElement.innerHTML = notesCode;
    }
    else {
        notesElement.innerHTML = `Add Your First Note`;
    }
}

displayNotes();

addBtn.addEventListener('click', (eventPara) => {
    eventPara.preventDefault();
    if (title.value != '' && note.value != '') {
        getItem();
        let myObj = {
            title: title.value,
            text: note.value
        }
        notesObj.push(myObj);
        localStorage.setItem('notes', JSON.stringify(notesObj));
        title.value = '';
        note.value = '';
    }
    displayNotes();
});

search.addEventListener("input", () => {
    let inputVal = search.value.toLowerCase();
    let noteCards = document.getElementsByClassName('noteCard');
    Array.from(noteCards).forEach((element) => {
        let cardTxt = element.getElementsByTagName("p")[0].innerText.toLowerCase();
        let titleText = element.getElementsByTagName("h5")[0].innerText.toLowerCase();
        if (cardTxt.includes(inputVal) || titleText.includes(inputVal)) {
            element.style.display = "block";
        }
        else {
            element.style.display = "none";
        }
    })
});

searchBtn.addEventListener('click', (eventPara) => {
    eventPara.preventDefault();
});