import requests
import json
from flask import Flask, request, render_template_string

url="http://localhost:11434/api/chat"


def llama3(prompt):
    data={
        "model":"llama3",
        "messages":[
            {
                "role":"user",
                "content": prompt
            }
        ],
        "stream":False
    }
    headers = {
        'Content-Type':'application/json'
    }

    response = requests.post(url,headers=headers,json=data)
    return(response.json()['message']['content'])



app = Flask(__name__)

@app.route('/')
def index():
    return render_template_string('''
        <form method="POST" action="/submit">
            <label for="input">Enter Prompt:</label>
            <input type="text" id="input" name="input">
            <input type="submit" value="Submit">
        </form>
    ''')

@app.route('/submit', methods=['POST'])
def submit():
    user_input = request.form['input']
    response = llama3(user_input)
    print(response)
    return f'Response: {response}'
    # return f'Response: {user_input}'

if __name__ == '__main__':
    app.run(debug=True)
