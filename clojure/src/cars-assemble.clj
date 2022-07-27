(ns cars-assemble)

(defn production-rate
  "Returns the assembly line's production rate per hour,
   taking into account its success rate"
  [speed]
  (* (get [0 1 0.9 0.8 0.77]
          (condp some #{speed}
            #{0} 0
            #{1 2 3 4} 1
            #{5 6 7 8} 2
            #{9}       3
            #{10}      4))
     speed 221))

(defn working-items
  "Calculates how many working cars are produced per minute"
  [speed]
  (int (/ (production-rate speed) 60)))
