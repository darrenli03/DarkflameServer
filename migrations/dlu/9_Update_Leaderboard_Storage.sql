ALTER TABLE leaderboard 
    ADD COLUMN hitPercentage INT NOT NULL DEFAULT 0,
    ADD COLUMN streak INT NOT NULL DEFAULT 0,
    ADD COLUMN bestLapTime INT NOT NULL DEFAULT 0,
    ADD COLUMN numWins INT NOT NULL DEFAULT 0,
    ADD COLUMN timesPlayed INT NOT NULL DEFAULT 1,
    MODIFY time INT NOT NULL DEFAULT 0;

ALTER TABLE leaderboard CHANGE time bestTime INT;
ALTER TABLE leaderboard CHANGE last_played last_played TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP() ON UPDATE CURRENT_TIMESTAMP();

UPDATE leaderboard SET streak = bestTime where game_id = 1864;
