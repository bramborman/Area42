SELECT Nazev, Autor, Id FROM Knihovna WHERE Nazev = 'Kmotr' OR ID = 3 ORDER BY Nazev, ID
INSERT INTO Knihovna VALUES ('Pandafrog', NULL, 'Frogfrog')
--Selecting by NULL using IS or IS NOT
SELECT * FROM Knihovna WHERE ZapujcenoID IS NULL
DELETE FROM Knihovna WHERE Id = 6
SELECT * FROM Knihovna
UPDATE Knihovna SET Nazev = 'Frogfrog', Autor = 'Pandafrog' WHERE Id = 16
SELECT COUNT(Nazev) AS Pocet, Nazev FROM Knihovna GROUP BY Nazev
SELECT TOP 3 * FROM Knihovna
SELECT * FROM Knihovna WHERE Nazev LIKE 'Pandafrog%'
SELECT k.Nazev, s.Jmeno, s.Prijmeni FROM Knihovna k INNER JOIN SkolaZaci s ON k.ZapujcenoID = s.Id WHERE s.Prijmeni = 'Pandafrog'
SELECT k.Nazev, s.Jmeno, s.Prijmeni FROM Knihovna k LEFT JOIN SkolaZaci s ON k.ZapujcenoID = s.Id
SELECT k.Nazev, s.Jmeno, s.Prijmeni FROM Knihovna k FULL OUTER JOIN SkolaZaci s ON k.ZapujcenoID = s.Id
