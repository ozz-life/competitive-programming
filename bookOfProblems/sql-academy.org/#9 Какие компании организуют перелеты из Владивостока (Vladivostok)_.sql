select company.name FROM company 
inner join trip on company.id = trip.company
where town_from = 'Vladivostok';