select DISTINCT company.name from company
inner join trip on company.id = trip.company
where trip.plane = 'Boeing';