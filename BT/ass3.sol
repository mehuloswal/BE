// SPDX-License-Identifier: MIT
pragma solidity ^0.8;

contract Banking {
    mapping(address => uint256) public user_account;
    mapping(address => bool) public user_exists;

    function create_account() public payable returns (string memory) {
        require(user_exists[msg.sender] == false, "Account already created");
        if (msg.value == 0) {
            user_account[msg.sender] = 0;
            user_exists[msg.sender] = true;
            return "Account created";
        }
        require(user_exists[msg.sender] == false, " Account already created");
        user_account[msg.sender] = msg.value;
        user_exists[msg.sender] = true;
        return "Account created";
    }

    function deposit() public payable returns (string memory) {
        require(user_exists[msg.sender] == true, "Account not created");
        require(msg.value > 0, "Value for deposit is Zero");
        user_account[msg.sender] = user_account[msg.sender] + msg.value;
        return "Deposited Succesfully";
    }

    function withdraw(uint256 amount) public payable returns (string memory) {
        require(user_account[msg.sender] > amount, "Insufficeint balance");
        require(user_exists[msg.sender] == true, "Account not created");
        require(amount > 0, "Amount should be more than zero");
        user_account[msg.sender] = user_account[msg.sender] - amount;
        return "Withdrawal Successfull";
    }

    function transfer(address payable userAddress, uint256 amount)
        public
        returns (string memory)
    {
        require(
            user_account[msg.sender] > amount,
            "Insufficeint balance in Bank account"
        );
        require(user_exists[msg.sender] == true, "Account is not created");
        require(
            user_exists[userAddress] == true,
            "Tranfer account does not exist"
        );
        require(amount > 0, "Amount should be more than zero");
        user_account[msg.sender] = user_account[msg.sender] - amount;
        user_account[userAddress] = user_account[userAddress] + amount;
        return "Transfer succesful";
    }

    function send_amt(address payable toAddress, uint256 amount)
        public
        payable
        returns (string memory)
    {
        require(
            user_account[msg.sender] > amount,
            "Insufficeint balance in Bank account"
        );
        require(user_exists[msg.sender] == true, "Account is not created");
        require(amount > 0, "Amount should be more than zero");
        user_account[msg.sender] = user_account[msg.sender] - amount;
        toAddress.transfer(amount);
        return "Transfer success";
    }

    function user_balance() public view returns (uint256) {
        return user_account[msg.sender];
    }

    function account_exist() public view returns (bool) {
        return user_exists[msg.sender];
    }
}
