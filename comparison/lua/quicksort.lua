function quicksort(array, start, ending)
    if start >= 0 and ending >= 0 and start < ending then
        local crossing = hoare_partition(array, start, ending)

        quicksort(array, start, crossing)
        quicksort(array, crossing + 1, ending)
    end
end

function hoare_partition(array, start, ending)
    local pivot = array[math.floor((start + ending) / 2)]

    local i = start - 1
    local j = ending + 1

    while true do
        i = i + 1
        while array[i] < pivot do
            i = i + 1
        end

        j = j - 1
        while array[j] > pivot do
            j = j - 1
        end

        if i >= j then
            return j
        end

        local temp = array[i]
        array[i] = array[j]
        array[j] = temp
    end
end

-- create array
math.randomseed(os.time())

local count = 10000000
local maximum = 4294967295
-- count = 10
-- maximum = 10

local array = {}
for i = 1, count do
    array[i] = math.random(0, maximum)
end

-- test
local start = os.clock()
quicksort(array, 1, count)
local ending = os.clock()

print("custom quicksort", ending - start)

-- create array
array = {}
for i = 1, count do
    array[i] = math.random(0, maximum)
end

start = os.clock()
table.sort(array, function(left, right)
    return left < right
end)
ending = os.clock()

print("table.sort", ending - start)
