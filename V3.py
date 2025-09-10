import random
import time
import csv
from datetime import datetime
import os

# Questions and answers
questions = [
    "What is the derivative of e^(x^2) with respect to x?",
    "In fluid mechanics, Bernoulli's equation assumes:",
    "Which type of immunoglobulin is most abundant in human serum?",
    "What is the primary component of the Sun's core?",
    "The process of transcription in eukaryotes occurs in:",
    "The hybridization of carbon in ethyne (acetylene, C₂H₂) is:",
    "The energy of a photon is given by:",
    "Which structure of a protein is determined by hydrogen bonding between backbone atoms?",
    "In a SWOT analysis, 'W' stands for:",
    "Which philosopher introduced the concept of 'categorical imperative'?",
    "Which of the following is NOT a type of logical fallacy?",
    "In fluid mechanics, Bernoulli's equation assumes:",
    "Which type of immunoglobulin is most abundant in human serum?",
    "Which phase of the cardiac cycle involves ventricular contraction?",
    "What is the primary component of the Sun's core?",
    "Which galaxy type is the most abundant in the universe?",
    "The process of transcription in eukaryotes occurs in:",
    "Which organelle is responsible for producing ATP?",
    "Which type of bond involves the sharing of electron pairs between atoms?",
    "Which law states that energy cannot be created or destroyed?",
    "Which structure of a protein is determined by hydrogen bonding between backbone atoms?",
    "The Michaelis-Menten constant (Km) represents:",
    "What is the main product when ethanol is oxidized using acidified potassium dichromate?",
    "Which of the following is a key principle of financial accounting?",
    "The principle of STARE DECISIS refers to:",
    "Which international organization oversees global intellectual property rights?",
    "Who wrote 'The Republic', a foundational work in Western philosophy?",
    "Which movement is associated with abstract expressionism in art?",
    "Which layer of Earth is primarily composed of iron and nickel?",
    "Which gas is a primary contributor to the greenhouse effect?",
    "Which class of animals is characterized by having hair and mammary glands?",
    "Coral reefs are primarily composed of:",
    "The event horizon of a black hole is defined as:",
    "Which spacecraft was the first to fly by Pluto?",
    "The effective temperature of the Sun's surface is approximately:",
    "Which term describes the distance light travels in one year?",
    "What is the integral of sin(x) with respect to x?",
    "Which of the following is a type of renewable energy?",
    "The Nyquist criterion is used to determine:",
    "In thermodynamics, which property is an extensive property?",
    "Which hormone regulates blood sugar levels by facilitating glucose uptake in cells?",
    "Which microorganism is responsible for tuberculosis?",
    "What is the name of the region around a star where liquid water could exist on a planet's surface?",
    "Which planet in the Solar System has the largest number of moons?",
    "In DNA, adenine pairs with:",
    "What is the main photosynthetic pigment in plants?",
    "What is the oxidation state of sulfur in H₂SO₄?",
    "The bond angle in a water molecule is approximately:",
    "What is the SI unit of magnetic flux?",
    "Which type of wave is not capable of traveling through a vacuum?",
    "Enzymes are primarily composed of:",
    "Which of the following is an example of a competitive inhibitor?",
    "What does the term 'liquidity' refer to in finance?",
    "Which leadership style involves delegating decision-making authority to subordinates?",
    "What does the term 'habeas corpus' mean?",
    "Which law regulates anti-competitive practices in the European Union?",
    "What is the main purpose of a thesis in academic writing?",
    "In statistics, the mean of a data set is calculated by:",
    "In electrical circuits, the unit of inductance is:",
    "In computer networking, which protocol ensures reliable data transfer?",
    "The hormone responsible for regulating circadian rhythm is:",
    "Which vitamin is essential for blood clotting?",
    "Which planet has the highest surface temperature in the Solar System?",
    "The Hubble Space Telescope primarily observes in which type of light?",
    "What is the term for a sequence of DNA that codes for a specific protein?",
    "Which process results in the formation of gametes?",
    "Which element has the highest electronegativity?",
    "The pH of a neutral solution at 25°C is:",
    "The speed of light in a vacuum is approximately:",
    "The second law of thermodynamics states that:",
    "The most common secondary structure in proteins is",
    "ATP is primarily produced in which part of the cell?",
    "In economics, the law of demand states that:",
    "The primary goal of financial management is to:",
    "The concept of 'natural justice' includes principles of:",
    "Which legal system is primarily based on written statutes?",
    "Which philosopher is known for the concept of 'tabula rasa'?",
    "In academic research, a null hypothesis is:",
    "In thermodynamics, the Carnot cycle is:",
    "What is the primary function of a rectifier?",
    "The Glasgow Coma Scale is used to assess:",
    "Which of the following is an example of an autoimmune disease?",
    "The largest moon of Saturn is:",
    "The cosmic microwave background radiation is evidence for:",
    "Which process involves the exchange of genetic material between homologous chromosomes?",
    "The smallest unit of life capable of independent existence is:",
    "The bond angle in a water molecule is approximately:",
    "What is the standard molar volume of an ideal gas at STP (Standard Temperature and Pressure)?",
    "The Heisenberg Uncertainty Principle is mathematically expressed as:",
    "What is the SI unit of magnetic flux?",
    "Which molecule serves as the primary energy currency of the cell?",
    "Which technique is used to separate proteins based on size?",
    "A 'bear market' in finance refers to:",
    "The four Ps of marketing include:",
    "In contract law, an offer is considered valid when:",
    "The International Court of Justice is located in:",
    "In genetic engineering, which enzyme is used to cut DNA at specific sequences?",
    "The Hardy-Weinberg principle assumes which of the following conditions?",
    "Which phenomenon demonstrates the wave nature of light?",
    "In special relativity, what remains constant for all observers?"
]

options = [
    ["1) 2xe^(x^2)", "2) e^(x^2)", "3) x^2e^(x^2)", "4) xe^x"],
    ["1) Compressible flow", "2) Viscous flow", "3) Steady and incompressible flow", "4) Ernest Hemingway"],
    ["1) IgA", "2) IgE", "3) IgG", "4) IgM"],
    ["1) Helium", "2) Hydrogen", "3) Carbon", "4) Iron"],
    ["1) Ribosomes", "2) Cytoplasm", "3) Nucleus", "4) Golgi apparatus"],
    ["1) sp³", "2) sp²", "3) sp", "4) sp³d"],
    ["1) hv", "2) h/v", "3) hc/λ", "4) Both a and c"],
    ["1) Primary structure", "2) Secondary structure", "3) Tertiary structure", "4) Quaternary structure"],
    ["1) Weakness", "2) Weight", "3) Worth", "4) Will"],
    ["1) Kant", "2) Nietzsche", "3) Hume", "4) Locke"],
    ["1) Ad Hominem", "2) Straw Man", "3) Red Herring", "4) Hindsight Bias"],
    ["1) Compressible flow", "2) Viscous flow", "3) Steady and incompressible flow", "4) Variable density"],
    ["1) IgA", "2) IgE", "3) IgG", "4) IgM"],
    ["1) Systole", "2) Diastole", "3) Isovolumetric Relaxation", "4) Ventricular Filling"],
    ["1) Helium", "2) Hydrogen", "3) Carbon", "4) Iron"],
    ["1) Spiral", "2) Elliptical", "3) Irregular", "4) Lenticular"],
    ["1) Ribosomes", "2) Cytoplasm", "3) Nucleus", "4) Golgi apparatus"],
    ["1) Nucleus", "2) Mitochondria", "3) Ribosomes", "4) Endoplasmic Reticulum"],
    ["1) Ionic bond", "2) Covalent bond", "3) Metallic bond", "4) Hydrogen bond"],
    ["1) First Law of Thermodynamics", "2) Second Law of Thermodynamics", "3) Conservation of Momentum", "4) Coulomb's Law"],
    ["1) Primary structure", "2) Secondary structure", "3) Tertiary structure", "4) Quaternary structure"],
    ["1) The maximum reaction rate", "2) The substrate concentration at half the maximum reaction rate", "3) The enzyme concentration", "4) The rate of substrate binding"],
    ["1) Methane", "2) Ethene", "3) Acetaldehyde", "4) Acetic acid"],
    ["1) Consistency", "2) Diversity", "3) Equity", "4) Volatility"],
    ["1) Statutory interpretation", "2) Precedent-based decision-making", "3) Judicial activism", "4) Case dismissal"],
    ["1) WTO", "2) WIPO", "3) IMF", "4) UN"],
    ["1) Socrates", "2) Plato", "3) Aristotle", "4) Descartes"],
    ["1) Surrealism", "2) Impressionism", "3) Cubism", "4) Action painting"],
    ["1) Crust", "2) Mantle", "3) Outer core", "4) Inner core"],
    ["1) Oxygen", "2) Nitrogen", "3) Carbon dioxide", "4) Helium"],
    ["1) Reptiles", "2) Amphibians", "3) Mammals", "4) Birds"],
    ["1) Silica", "2) Calcium carbonate", "3) Magnesium sulfate", "4) Sodium chloride"],
    ["1) The distance at which light cannot escape", "2) The boundary where gravity is zero", "3) The surface of the singularity", "4) The point of maximum radiation"],
    ["1) Voyager 1", "2) New Horizons", "3) Cassini", "4) Hubble"],
    ["1) 4,000 K", "2) 5,800K", "3) 10,000 K", "4) 15,000 K"],
    ["1) Astronomical Unit", "2) Parsec", "3) Light-Year", "4) Kilometer"],
    ["1) cos(x)", "2) -cos(x)", "3) -sin(x)", "4) tan(x)"],
    ["1) Natural Gas", "2) Solar Energy", "3) Nuclear Energy", "4) Coal"],
    ["1) Stability of a control system", "2) Power efficiency", "3) Signal distortion", "4) Material strength"],
    ["1) Pressure", "2) Temperature", "3) Entropy", "4) Density"],
    ["1) Glucagon", "2) Insulin", "3) Adrenaline", "4) Cortisol"],
    ["1) Escherichia coli", "2) Mycobacterium tuberculosis", "3) Streptococcus pneumoniae", "4) Bacillus anthracis"],
    ["1) Kuiper Belt", "2) Goldilocks Zone", "3) Oort Cloud", "4) Schwarzschild Radius"],
    ["1) Jupiter", "2) Saturn", "3) Uranus", "4) Neptune"],
    ["1) Cytosine", "2) Thymine", "3) Guanine", "4) Uracil"],
    ["1) Chlorophyll a", "2) Carotene", "3) Xanthophyll", "4) Anthocyanin"],
    ["1) +4", "2) +6", "3) -2", "4) 0"],
    ["1) 90°", "2) 104.5°", "3) 109.5°", "4) 120°"],
    ["1) Tesla", "2) Weber", "3) Henry", "4) Gauss"],
    ["1) Radio waves", "2) Sound waves", "3) Light waves", "4) X-rays"],
    ["1) Nucleotides", "2) Lipids", "3) Proteins", "4) Carbohydrates"],
    ["1) ATP in glycolysis", "2) Malonate in succinate dehydrogenase", "3) FAD in electron transport chain", "4) NAD+ in Krebs cycle"],
    ["1) Profitability of assets", "2) Conversion of assets to cash", "3) Return on investments", "4) Reduction in liabilities"],
    ["1) Autocratic", "2) Democratic", "3) Laissez-faire", "4) Transformational"],
    ["1) By the court's authority", "2) Produce the body", "3) Let the buyer beware", "4) The thing speaks for itself"],
    ["1) Sherman Act", "2) Competition Act", "3) GDPR", "4) Article 101 of TFEU"],
    ["1) To summarize existing knowledge", "2) To propose a central argument or idea", "3) To provide examples of a topic", "4) To list references"],
    ["1) Dividing the sum of all values by the number of values", "2) Finding the middle value of the sorted data set", "3) Calculating the square root of the variance", "4) Determining the most frequent value"],
    ["1) Tesla", "2) Farad", "3) Henry", "4) Coulomb"],
    ["1) TCP", "2) UDP", "3) HTTP", "4) FTP"],
    ["1) Insulin", "2) Melatonin", "3) Thyroxine", "4) Adrenaline"],
    ["1) Vitamin A", "2) Vitamin B12", "3) Vitamin C", "4) Vitamin K"],
    ["1) Mercury", "2) Venus", "3) Mars", "4) Jupiter"],
    ["1) Radio waves", "2) Visible and ultraviolet", "3) Gamma rays", "4) Infrared"],
    ["1) Genome", "2) Gene", "3) Chromosome", "4) Codon"],
    ["1) Mitosis", "2) Meiosis", "3) Binary fission", "4) Budding"],
    ["1) Oxygen", "2) Fluorine", "3) Nitrogen", "4) Chlorine"],
    ["1) 0", "2) 7", "3) 14", "4) 1"],
    ["1) 3×10^8 m/s", "2) 3×10^6 m/s", "3) 3×10^10 m/s", "4) 3×10^12 m/s"],
    ["1) Energy cannot be created or destroyed", "2) The entropy of an isolated system always increases", "3) For every action, there is an equal and opposite reaction", "4) Energy transfer is 100 percent efficient"],
    ["1) Alpha helix", "2) Beta sheet", "3) Random coil", "4) Both a and b"],
    ["1) Cytoplasm", "2) Mitochondria", "3) Golgi apparatus", "4) Ribosome"],
    ["1) Higher prices lead to higher demand", "2) Lower prices lead to higher demand", "3) Price has no effect on demand", "4) Demand is inversely proportional to supply"],
    ["1) Maximize revenue", "2) Maximize shareholder wealth", "3) Minimize costs", "4) Ensure customer satisfaction"],
    ["1) Equity and common sense", "2) Bias and discrimination", "3) Autocracy and sovereignty", "4) Speedy and non-transparent trials"],
    ["1) Common law", "2) Civil law", "3) Islamic law", "4) Tribal law"],
    ["1) John Locke", "2) Immanuel Kant", "3) Friedrich Nietzsche", "4) René Descartes"],
    ["1) The hypothesis being tested for rejection", "2) A hypothesis that is always accepted", "3) A statement of causation", "4) An untestable claim"],
    ["1) An idealized thermodynamic cycle", "2) A practical refrigeration cycle", "3) An isothermal expansion process", "4) A heat transfer process in engines"],
    ["1) Amplify signals", "2) Convert AC to DC", "3) Store electrical energy", "4) Measure current"],
    ["1) Heart function", "2) Liver damage", "3) Neurological function", "4) Lung capacity"],
    ["1) Diabetes mellitus type 2", "2) Rheumatoid arthritis", "3) Tuberculosis", "4) Influenza"],
    ["1) Europa", "2) Titan", "3) Ganymede", "4) Callisto"],
    ["1) Dark energy", "2) The Big Bang theory", "3) Galaxy formation", "4) Black hole evaporation"],
    ["1) Crossing over", "2) Independent assortment", "3) Fertilization", "4) DNA replication"],
    ["1) Atom", "2) Cell", "3) Tissue", "4) Organelle"],
    ["1) 180°", "2) 109.5°", "3) 120°", "4) 104.5°"],
    ["1) 22.4 L", "2) 24.0 L", "3) 20.1 L", "4) 18.0 L"],
    ["1) ΔxΔp ≥ h/4π", "2) E = mc²", "3) F = ma", "4) ΔEΔt ≤ h"],
    ["1) Tesla", "2) Weber", "3) Gauss", "4) Ampere"],
    ["1) DNA", "2) ATP", "3) NADH", "4) Glucose"],
    ["1) Western blotting", "2) Gel filtration chromatography", "3) SDS-PAGE", "4) Mass spectrometry"],
    ["1) A market with rising stock prices", "2) A market with falling stock prices", "3) A stable stock market", "4) A volatile stock market"],
    ["1) Product, Price, Process, Performance", "2) Product, Price, Place, Promotion", "3) Planning, People, Price, Place", "4) Price, Promotion, Profit, People"],
    ["1) It is vague and open to interpretation", "2) It is clear, definite, and communicated", "3) It is implied but not communicated", "4) It is agreed upon without acceptance"],
    ["1) Geneva", "2) New York", "3) The Hague", "4) Paris"],
    ["1) DNA polymerase", "2) Ligase", "3) Restriction endonuclease", "4) Helicase"],
    ["1) Non-random mating", "2) Natural selection", "3) Large population size", "4) Mutation occurring frequently"],
    ["1) Photoelectric effect", "2) Double-slit experiment", "3) Compton scattering", "4) Zeeman effect"],
    ["1) Velocity of light", "2) Time intervals", "3) Length of objects", "4) Mass of moving particles"]
]

correct_answers = [
    1,3,3,2,3,3,4,2,1,1,
    4,3,3,1,2,2,3,2,2,1,
    2,2,3,1,2,2,2,4,4,3,
    3,2,1,2,2,3,2,2,1,3,
    2,2,2,2,2,1,2,2,2,2,
    3,2,2,3,2,4,2,1,3,1,
    2,4,2,2,2,2,2,2,1,2,
    4,2,2,2,1,2,1,1,1,2,
    3,2,2,2,1,2,4,1,1,2,
    2,3,2,2,2,3,3,3,2,1
]

def save_score(player_name, score, total_time):
    """Save player score to CSV file"""
    file_exists = os.path.isfile('scores.csv')
    
    with open('scores.csv', 'a', newline='') as file:
        writer = csv.writer(file)
        if not file_exists:
            writer.writerow(['Name', 'Score', 'Time (seconds)', 'Date'])
        
        current_date = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        writer.writerow([player_name, score, total_time, current_date])

def display_high_scores():
    """Display the top 10 high scores"""
    try:
        with open('scores.csv', 'r') as file:
            reader = csv.reader(file)
            next(reader)  # Skip header row
            
            scores = []
            for row in reader:
                if len(row) >= 4:
                    scores.append({
                        'name': row[0],
                        'score': int(row[1]),
                        'time': int(row[2]),
                        'date': row[3]
                    })
            
            # Sort by score (descending) and time (ascending)
            scores.sort(key=lambda x: (-x['score'], x['time']))
            
            print("\n=== HIGH SCORES ===")
            print(f"{'Name':<20} {'Score':<10} {'Time (sec)':<15} {'Date':<25}")
            print("-" * 70)
            
            for i, score in enumerate(scores[:10]):  # Show top 10
                print(f"{score['name']:<20} {score['score']:<10} {score['time']:<15} {score['date']:<25}")
                
    except FileNotFoundError:
        print("No high scores available yet.")

def get_grade(score):
    """Return grade based on score"""
    if score == 0:
        return "Need studying."
    elif 1 <= score <= 4:
        return "Try better next time."
    elif score == 5:
        return "Not Good but Not Bad."
    elif 6 <= score <= 7:
        return "Good but Try harder."
    elif 8 <= score <= 9:
        return "Very good and Keep it up!"
    elif score == 10:
        return "Excellent!!!"
    return ""

def main():
    random.seed(time.time())
    
    print("Welcome to the Quiz Game!")
    print("1. Play Quiz")
    print("2. View High Scores")
    print("3. Exit")
    
    try:
        menu_choice = int(input("Choose an option (1-3): "))
    except ValueError:
        print("Invalid choice. Exiting program.")
        return
    
    if menu_choice == 1:
        player_name = input("Enter your name: ")
        play_option = input(f"Hello, {player_name}! Do you want to play the quiz game? (y/n): ")
        
        if play_option.lower() != 'y':
            print(f"Game ended. Thank you, {player_name}!")
            return
        
        time_limit = 10  # Time limit per question in seconds
        score = 0
        
        # Select 10 unique random questions
        selected_indices = random.sample(range(len(questions)), 10)
        
        total_start_time = time.time()
        
        for i, question_index in enumerate(selected_indices):
            print(f"\nQuestion {i+1}: {questions[question_index]}")
            for option in options[question_index]:
                print(option)
            
            print(f"You have {time_limit} seconds to answer!")
            
            start_time = time.time()
            
            try:
                user_answer = int(input("Your answer (1-4): "))
            except ValueError:
                user_answer = 0  # Invalid answer
            
            end_time = time.time()
            elapsed_time = end_time - start_time
            
            if elapsed_time > time_limit:
                print(f"Time's up! The correct answer was {correct_answers[question_index]}.")
            elif user_answer == correct_answers[question_index]:
                print("Correct!")
                score += 1
            else:
                print(f"Incorrect. The correct answer was {correct_answers[question_index]}.")
            
            print(f"Time taken for this question: {elapsed_time:.2f} seconds")
        
        total_end_time = time.time()
        total_time = int(total_end_time - total_start_time)
        
        print(f"\nQuiz over! {player_name}, you scored {score} out of 10.")
        print(f"Total time taken for the quiz: {total_time} seconds")
        print(f"Grade: {get_grade(score)}")
        
        # Save the score
        save_score(player_name, score, total_time)
        print("Your score has been saved!")
        
    elif menu_choice == 2:
        display_high_scores()
    elif menu_choice == 3:
        print("Thank you for playing! Goodbye!")
    else:
        print("Invalid choice. Exiting program.")

if __name__ == "__main__":
    main()
