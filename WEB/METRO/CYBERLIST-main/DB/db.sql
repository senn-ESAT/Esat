-- Creazione della tabella users
CREATE TABLE users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    psw VARCHAR(255) NOT NULL,
    pp BLOB NULL -- Campo facoltativo per memorizzare un'immagine
);

-- Creazione della tabella event
CREATE TABLE event (
    event_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT, -- connessione tra evento e utente
    title VARCHAR(100) NOT NULL, -- nome evento
    descriptions TEXT, -- descrizione evento
    giorno DATE, -- data di scadenza
    ended BOOLEAN DEFAULT FALSE, -- false = incompleta, true = completata
    FOREIGN KEY (user_id) REFERENCES users(user_id) -- collegamento all'utente
);

-- Creazione della tabella daily
CREATE TABLE daily (
    daily_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT, -- connessione tra task e utente
    giorni INT,
    descriptions TEXT, -- descrizione task
    inizio TIME, -- ora inizio
    fine TIME, -- ora fine
    ended BOOLEAN DEFAULT FALSE, -- false = incompleta, true = completata
    FOREIGN KEY (user_id) REFERENCES users(user_id) -- collegamento all'utente
);