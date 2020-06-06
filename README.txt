# Scheduling-Reservations
Simulating some people trying to reserve seats at a restaurant for dinner

---------------------

Assumptions:

1. The restaurant takes reservations anywhere from 4pm until 9pm. That means, someone can phone in and ask to reserve a table for a certain number of people starting at some specific time in the range of 4pm until 9pm. The people are allowed to stay past 9pm, but no more reservations can be made after 9pm.

2. The restaurant can seat at most 80 people at any time, on any day of the week. Reservations may be made at 15-minute intervals starting at 4pm. Hence, 4:00pm, 4:15pm, 4:30pm, 4:45pm, 5:00pm, 5:15pm, ...., 8:45pm, 9:00pm.

3. The program keep track of reservations by using a 2D array to indicate the number of patrons in the restaurant at any given timeslot.

4. The program attempt to make 100 random (be unique each time runs) reservations by choosing: 
  - A random day of the week
  - A random timeslot (i.e., there are 21 options from 4pm-9pm)
  - A random size (i.e., number of people) for that reservation which can be at most 40

5. For each attempted reservation, the program print the number of people for the reservation, the day of the week and the start time of the reservation.

6. If the reservation is able to be made, it should indicate that the reservation was accepted, otherwise it should indicate that it was denied.

7. In order to accept a reservation, the program estimate the length of stay for each reservation. Assume the following:
  - If the reservation is for 2 people, the estimate length of stay is 60 minutes.
  - If the reservation is between 3-7 people, the estimate is for 75 minutes.
  - If the reservation is between 8-11 people, the estimate is for 105 minutes.
  - Otherwise the estimate should be for 120 minutes.

8. The program accept the reservation if the restaurant can hold that many people for the duration of the estimated length of stay. 
For example, if a 5pm reservation for 4 people is made, the program ensure that there are at most 76 people.
(i.e., restaurant capacity minus the reservation size) currently reserved for the following timeslots: 5:00pm, 5:15pm, 5:30pm, 5:45pm and 6:00pm. If any are over the value of 76, then the reservation should not be made, it should be denied.)

---------------------

Example Outcome:
Appointment call # 1:  3 people recervation made on day Sun, arrival time 5:45 pm
Appointment call # 2:  26 people recervation made on day Sat, arrival time 7:15 pm
Appointment call # 3:  15 people recervation made on day Tue, arrival time 6:00 pm
Appointment call # 4:  38 people recervation made on day Mon, arrival time 5:30 pm
Appointment call # 5:  34 people recervation made on day Sun, arrival time 9:00 pm
Appointment call # 6:  38 people recervation made on day Fri, arrival time 8:00 pm
Appointment call # 7:  10 people recervation made on day Thu, arrival time 6:30 pm
Appointment call # 8:  1 people recervation made on day Fri, arrival time 7:45 pm
Appointment call # 9:  36 people recervation made on day Mon, arrival time 4:45 pm
Appointment call # 10:  21 people recervation made on day Tue, arrival time 7:30 pm
Appointment call # 11:  2 people recervation made on day Thu, arrival time 8:15 pm
Appointment call # 12:  17 people recervation made on day Sat, arrival time 6:00 pm
Appointment call # 13:  11 people recervation made on day Sun, arrival time 4:15 pm
Appointment call # 14:  39 people recervation made on day Thu, arrival time 7:15 pm
Appointment call # 15:  35 people recervation made on day Sun, arrival time 4:00 pm
Appointment call # 16:  12 people recervation made on day Fri, arrival time 6:45 pm
Appointment call # 17:  7 people recervation made on day Sat, arrival time 8:00 pm
Appointment call # 18:  11 people recervation made on day Fri, arrival time 5:45 pm
Appointment call # 19:  8 people recervation made on day Sun, arrival time 8:15 pm
Appointment call # 20:  7 people recervation made on day Sun, arrival time 5:30 pm
Appointment call # 21:  31 people recervation made on day Fri, arrival time 5:45 pm
Appointment call # 22:  37 people recervation made on day Wed, arrival time 6:00 pm
Appointment call # 23:  5 people recervation made on day Sun, arrival time 4:00 pm
Appointment call # 24:  40 people recervation made on day Wed, arrival time 5:45 pm
Appointment call # 25:  23 people recervation made on day Fri, arrival time 7:15 pm
Appointment call # 26:  16 people recervation made on day Mon, arrival time 7:30 pm
Appointment call # 27:  32 people recervation made on day Sat, arrival time 5:15 pm
Appointment call # 28:  32 people recervation made on day Wed, arrival time 4:00 pm
Appointment call # 29:  37 people recervation made on day Mon, arrival time 8:15 pm
Appointment call # 30:  appointment denied
Appointment call # 31:  appointment denied
Appointment call # 32:  1 people recervation made on day Tue, arrival time 7:00 pm
Appointment call # 33:  34 people recervation made on day Sat, arrival time 7:00 pm
Appointment call # 34:  6 people recervation made on day Wed, arrival time 7:00 pm
Appointment call # 35:  7 people recervation made on day Thu, arrival time 8:15 pm
Appointment call # 36:  41 people recervation made on day Sun, arrival time 5:00 pm
Appointment call # 37:  19 people recervation made on day Fri, arrival time 5:30 pm
Appointment call # 38:  41 people recervation made on day Tue, arrival time 8:15 pm
Appointment call # 39:  16 people recervation made on day Wed, arrival time 9:00 pm
Appointment call # 40:  appointment denied
Appointment call # 41:  3 people recervation made on day Sat, arrival time 5:00 pm
Appointment call # 42:  7 people recervation made on day Sat, arrival time 8:00 pm
Appointment call # 43:  25 people recervation made on day Sat, arrival time 4:15 pm
Appointment call # 44:  25 people recervation made on day Fri, arrival time 8:45 pm
Appointment call # 45:  appointment denied
Appointment call # 46:  1 people recervation made on day Fri, arrival time 7:45 pm
Appointment call # 47:  9 people recervation made on day Sat, arrival time 4:30 pm
Appointment call # 48:  28 people recervation made on day Tue, arrival time 6:00 pm
Appointment call # 49:  appointment denied
Appointment call # 50:  3 people recervation made on day Thu, arrival time 5:15 pm
Appointment call # 51:  19 people recervation made on day Mon, arrival time 5:45 pm
Appointment call # 52:  appointment denied
Appointment call # 53:  17 people recervation made on day Mon, arrival time 9:00 pm
Appointment call # 54:  9 people recervation made on day Thu, arrival time 5:30 pm
Appointment call # 55:  appointment denied
Appointment call # 56:  appointment denied
Appointment call # 57:  appointment denied
Appointment call # 58:  appointment denied
Appointment call # 59:  1 people recervation made on day Thu, arrival time 6:30 pm
Appointment call # 60:  23 people recervation made on day Wed, arrival time 8:45 pm
Appointment call # 61:  17 people recervation made on day Sat, arrival time 7:15 pm
Appointment call # 62:  appointment denied
Appointment call # 63:  appointment denied
Appointment call # 64:  appointment denied
Appointment call # 65:  appointment denied
Appointment call # 66:  6 people recervation made on day Tue, arrival time 8:00 pm
Appointment call # 67:  appointment denied
Appointment call # 68:  appointment denied
Appointment call # 69:  15 people recervation made on day Thu, arrival time 7:45 pm
Appointment call # 70:  appointment denied
Appointment call # 71:  36 people recervation made on day Sun, arrival time 6:30 pm
Appointment call # 72:  appointment denied
Appointment call # 73:  27 people recervation made on day Sat, arrival time 5:00 pm
Appointment call # 74:  23 people recervation made on day Mon, arrival time 8:00 pm
Appointment call # 75:  24 people recervation made on day Thu, arrival time 8:30 pm
Appointment call # 76:  2 people recervation made on day Mon, arrival time 4:15 pm
Appointment call # 77:  appointment denied
Appointment call # 78:  appointment denied
Appointment call # 79:  appointment denied
Appointment call # 80:  38 people recervation made on day Thu, arrival time 4:15 pm
Appointment call # 81:  appointment denied
Appointment call # 82:  appointment denied
Appointment call # 83:  appointment denied
Appointment call # 84:  appointment denied
Appointment call # 85:  appointment denied
Appointment call # 86:  15 people recervation made on day Fri, arrival time 7:45 pm
Appointment call # 87:  25 people recervation made on day Sun, arrival time 8:00 pm
Appointment call # 88:  appointment denied
Appointment call # 89:  21 people recervation made on day Sat, arrival time 8:45 pm
Appointment call # 90:  19 people recervation made on day Thu, arrival time 6:15 pm
Appointment call # 91:  appointment denied
Appointment call # 92:  appointment denied
Appointment call # 93:  appointment denied
Appointment call # 94:  16 people recervation made on day Fri, arrival time 5:00 pm
Appointment call # 95:  38 people recervation made on day Sat, arrival time 8:30 pm
Appointment call # 96:  appointment denied
Appointment call # 97:  appointment denied
Appointment call # 98:  appointment denied
Appointment call # 99:  appointment denied
Appointment call # 100:  2 people recervation made on day Tue, arrival time 7:45 pm

       |Sum|Mon|Tue|Wed|Thu|Fri|Sat|
       |---|---|---|---|---|---|---|
04:00pm| 40| 34| 17| 32| 39| 24| 25|
04:15pm| 51| 36| 17| 32| 77|  0| 50|
04:30pm| 51| 36| 17| 32| 54|  0| 34|
04:45pm| 51| 38|  0| 32| 38|  0| 34|
05:00pm| 52| 38|  0|  0| 38| 16| 64|
05:15pm| 41| 36|  0|  0|  3| 16| 71|
05:30pm| 48| 74|  0|  0| 12| 35| 62|
05:45pm| 51| 57|  0| 40| 12| 77| 62|
06:00pm| 10| 57| 43| 77| 12| 61| 49|
06:15pm| 10| 57| 43| 77| 28| 61| 17|
06:30pm| 39| 19| 43| 77| 30| 42| 17|
06:45pm| 36|  0| 43| 37| 30| 12| 17|
07:00pm| 36|  0|  1|  6| 30| 12| 34|
07:15pm| 36|  0|  1|  6| 50| 35| 77|
07:30pm|  0| 16| 22|  6| 39| 35| 77|
07:45pm|  0| 16| 24|  6| 54| 40| 77|
08:00pm| 25| 39| 29|  0| 54| 78| 57|
08:15pm| 33| 76| 70|  0| 24| 55| 14|
08:30pm| 33| 60| 49|  0| 48| 55| 52|
08:45pm| 33| 60| 47| 23| 33| 63| 73|
09:00pm| 42| 54| 41| 39| 33| 25| 59|